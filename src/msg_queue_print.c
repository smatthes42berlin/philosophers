/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_queue_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:13:40 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/14 19:53:38 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static const char	*get_msg(int msg_type);
static void			print_eaten_enough(t_main_data *main_data);
static void			print_msg(t_message cur_message);
static BOOL	check_stop_printing(t_main_data *main_data,
								t_message cur_message);

void	print_msg_queue(t_main_data *main_data, t_message_queue *msg_queue)
{
	int			i;
	t_message	cur_message;

	i = 0;
	pthread_mutex_lock(&msg_queue->mutex);
	if (!main_data->stop_printing)
	{
		while (i < msg_queue->count)
		{
			cur_message = (msg_queue->messages)[(msg_queue->front + i)
				% MAX_MESSAGES];
			if (cur_message.msg_type != EATENENOUGH)
				print_msg(cur_message);
			else
				print_eaten_enough(main_data);
			if (check_stop_printing(main_data, cur_message) == TRUE)
				break ;
			i++;
		}
	}
	reset_queue(msg_queue);
	pthread_mutex_unlock(&msg_queue->mutex);
}

static BOOL	check_stop_printing(t_main_data *main_data, t_message cur_message)
{
	if (cur_message.msg_type == DEAD || cur_message.msg_type == EATENENOUGH)
	{
		main_data->stop_printing = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

static void	print_msg(t_message cur_message)
{
	printf("%ld %d %s\n", cur_message.timestamp, cur_message.philo_id,
			get_msg(cur_message.msg_type));
}

static void	print_eaten_enough(t_main_data *main_data)
{
	printf("all philosophers have eaten at least %d-times\n",
			main_data->min_times_eat);
}

static const char	*get_msg(int msg_type)
{
	if (msg_type == TAKEFORK)
		return ("has taken a fork");
	else if (msg_type == EATING)
		return ("is eating");
	else if (msg_type == SLEEPING)
		return ("is sleeping");
	else if (msg_type == THINKING)
		return ("is thinking");
	else if (msg_type == DEAD)
		return ("died");
	else
		return ("unknown");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:13:40 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/10 20:05:27 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*msg_routine(void *data)
{
	t_main_data *main_data;

	main_data = data;

	while (main_data->msg_status == RUNNING)
	{
		print_msg_queue(main_data, main_data->print_msg_queue);
		swap_queues(main_data);
		usleep(1000);
	}
	return (NULL);
}
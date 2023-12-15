/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:13:40 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/15 16:41:58 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*msg_routine(void *data)
{
	t_main_data	*main_data;

	main_data = data;
	while (read_sim_status_main(main_data) == RUNNING
		|| !main_data->stop_printing)
	{
		print_msg_queue(main_data, main_data->print_msg_queue);
		swap_queues(main_data);
		usleep(100);
	}
	return (NULL);
}

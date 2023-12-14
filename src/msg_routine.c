/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:13:40 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/14 19:34:41 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*msg_routine(void *data)
{
	t_main_data *main_data;

	main_data = data;

	// if (ensure_all_threads_created(main_data) == ERROR)
	// 	return (NULL);
	while (read_sim_status_main(main_data) == RUNNING
		|| !main_data->stop_printing)
	// while (TRUE)
	{
		print_msg_queue(main_data, main_data->print_msg_queue);
		swap_queues(main_data);
		usleep(1000);
	}
	return (NULL);
}
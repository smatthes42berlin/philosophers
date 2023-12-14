/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_queue_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:07:51 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/14 19:27:19 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_queue_msg(t_philo *philo, int msg_type)
{
	t_message	msg;

	if (get_time_stamp_ms(philo->main_data, &msg.timestamp) == ERROR)
		return (ERROR);
	msg.philo_id = philo->id;
	msg.msg_type = msg_type;
	enqueue(philo->main_data->collect_msg_queue, msg);
	return (1);
}

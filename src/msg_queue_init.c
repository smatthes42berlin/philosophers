/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_queue_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:13:40 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/14 08:54:19 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_queue(t_message_queue *msg_queue)
{
	reset_queue(msg_queue);
	if (pthread_mutex_init(&msg_queue->mutex, NULL) == -1)
		return (ERROR);
	return (1);
}

int	destroy_queue(t_message_queue *msg_queue)
{
	reset_queue(msg_queue);
	if (pthread_mutex_destroy(&(msg_queue->mutex)) != 0)
		return (ERROR);
	return (1);
}

void	reset_queue(t_message_queue *msg_queue)
{
	msg_queue->front = 0;
	msg_queue->rear = -1;
	msg_queue->count = 0;
}

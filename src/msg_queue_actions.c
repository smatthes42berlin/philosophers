/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_queue_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:13:40 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/14 20:03:55 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	enqueue(t_message_queue *msg_queue, t_message msg)
{
	pthread_mutex_lock(&msg_queue->mutex);
	if (msg_queue->count < MAX_MESSAGES)
	{
		msg_queue->rear = (msg_queue->rear + 1) % MAX_MESSAGES;
		msg_queue->messages[msg_queue->rear] = msg;
		msg_queue->count++;
	}
	pthread_mutex_unlock(&msg_queue->mutex);
}

t_message	dequeue(t_message_queue *msg_queue)
{
	t_message	msg;

	pthread_mutex_lock(&msg_queue->mutex);
	if (msg_queue->count > 0)
	{
		msg = msg_queue->messages[msg_queue->front];
		msg_queue->front = (msg_queue->front + 1) % MAX_MESSAGES;
		msg_queue->count--;
	}
	pthread_mutex_unlock(&msg_queue->mutex);
	return (msg);
}

void	swap_queues(t_main_data *main_data)
{
	t_message_queue	*tmp;

	pthread_mutex_lock(&main_data->collect_msg_queue->mutex);
	pthread_mutex_lock(&main_data->print_msg_queue->mutex);
	tmp = main_data->print_msg_queue;
	main_data->print_msg_queue = main_data->collect_msg_queue;
	main_data->collect_msg_queue = tmp;
	pthread_mutex_unlock(&main_data->print_msg_queue->mutex);
	pthread_mutex_unlock(&main_data->collect_msg_queue->mutex);
}
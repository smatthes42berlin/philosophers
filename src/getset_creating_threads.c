/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getset_creating_threads.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:05:54 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/15 16:42:41 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_creating_threads_status(t_main_data *main_data, BOOL val)
{
	pthread_mutex_lock(&main_data->all_threads_mutex);
	main_data->all_threads_created = val;
	pthread_mutex_unlock(&main_data->all_threads_mutex);
}

BOOL	read_creating_threads_status(t_main_data *main_data)
{
	BOOL	val;

	pthread_mutex_lock(&main_data->all_threads_mutex);
	val = main_data->all_threads_created;
	pthread_mutex_unlock(&main_data->all_threads_mutex);
	return (val);
}

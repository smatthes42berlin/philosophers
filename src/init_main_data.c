/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:01:42 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/15 14:57:49 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_queue_philo(t_main_data *main_data);
static int	init_main_mutex(t_main_data *main_data);
static void	init_primitive_values(t_main_data *main_data);

int	init_main_data(t_main_data *main_data)
{
	init_primitive_values(main_data);
	if (init_queue_philo(main_data) == ERROR)
		return (ERROR);
	main_data->philo_threads = malloc(sizeof(t_philo) * main_data->num_philo);
	if (!main_data->philo_threads)
		return (free_main_data(main_data, 2, ERROR));
	main_data->philo_monitor_threads = malloc(sizeof(t_philo)
			* main_data->num_philo);
	if (!main_data->philo_monitor_threads)
		return (free_main_data(main_data, 3, ERROR));
	if (init_main_mutex(main_data) == ERROR)
		return (ERROR);
	return (1);
}

static int	init_main_mutex(t_main_data *main_data)
{
	if (pthread_mutex_init(&main_data->all_threads_mutex, NULL) != 0)
		return (free_main_data(main_data, 4, -1));
	if (pthread_mutex_init(&main_data->num_min_times_eat_mutex, NULL) != 0)
		return (free_main_data(main_data, 5, -1));
	if (pthread_mutex_init(&main_data->sim_status_mutex, NULL) != 0)
		return (free_main_data(main_data, 6, -1));
	return (1);
}

static int	init_queue_philo(t_main_data *main_data)
{
	reset_queue(&main_data->msg_queue_1);
	reset_queue(&main_data->msg_queue_2);
	if (pthread_mutex_init(&main_data->print_msg_queue_mutex, NULL) != 0)
		return (free_main_data(main_data, 0, -1));
	if (pthread_mutex_init(&main_data->collect_msg_queue_mutex, NULL) != 0)
		return (free_main_data(main_data, 1, -1));
	main_data->print_msg_queue = &main_data->msg_queue_1;
	main_data->collect_msg_queue = &main_data->msg_queue_2;
	return (1);
}

static void	init_primitive_values(t_main_data *main_data)
{
	main_data->num_eaten_min_times = 0;
	main_data->all_threads_created = FALSE;
	main_data->stop_printing = FALSE;
	main_data->sim_status = RUNNING;
	main_data->time_to_think = main_data->time_to_eat * 2
		- main_data->time_to_sleep;
	if (main_data->time_to_think < 0 || main_data->num_philo % 2 == 0)
		main_data->time_to_think = 0;
}

int	free_main_data(t_main_data *main_data, int which, int code)
{
	if (which >= 1)
		pthread_mutex_destroy(&(main_data->print_msg_queue_mutex));
	if (which >= 2)
		pthread_mutex_destroy(&(main_data->collect_msg_queue_mutex));
	if (which >= 3)
		free(main_data->philo_threads);
	if (which >= 4)
		free(main_data->philo_monitor_threads);
	if (which >= 5)
		pthread_mutex_destroy(&(main_data->all_threads_mutex));
	if (which >= 6)
		pthread_mutex_destroy(&(main_data->num_min_times_eat_mutex));
	if (which >= 7)
		pthread_mutex_destroy(&(main_data->sim_status_mutex));
	return (code);
}

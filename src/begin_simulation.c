/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:07:51 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/18 11:26:29 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	wait_for_stop_flag(t_main_data *main_data);
static void	tell_philo_threads_to_stop(t_main_data *main_data, int status);
static int	create_threads(t_main_data *main_data);
static int	join_threads(t_main_data *main_data, int other_threads,
				int num_philo_thread);

int	begin_simulation(t_main_data *main_data)
{
	int	status;

	if (create_threads(main_data) == ERROR)
		return (free_all_data(main_data, ERROR));
	if (gettimeofday(&main_data->sim_start, NULL) == -1)
		return (join_threads(main_data, 2, main_data->num_philo));
	write_creating_threads_status(main_data, 1);
	status = wait_for_stop_flag(main_data);
	tell_philo_threads_to_stop(main_data, status);
	join_threads(main_data, 2, main_data->num_philo);
	return (0);
}

static int	wait_for_stop_flag(t_main_data *main_data)
{
	int	status;

	status = read_sim_status_main(main_data);
	while (status == RUNNING)
	{
		status = read_sim_status_main(main_data);
		usleep(1000);
	}
	return (status);
}

static void	tell_philo_threads_to_stop(t_main_data *main_data, int status)
{
	int	i;

	i = 0;
	while (i < main_data->num_philo)
	{
		write_sim_status_philo(main_data->philos + i, status);
		i++;
	}
}

static int	create_threads(t_main_data *main_data)
{
	int	i;

	if (pthread_create(&main_data->printer_thread, NULL, &msg_routine,
			main_data) != 0)
		return (ERROR);
	if (pthread_create(&main_data->philo_monitor_thread, NULL,
			&philo_monitor_routine, main_data) != 0)
		return (join_threads(main_data, 1, 0));
	if (main_data->min_times_eat >= 0)
		if (pthread_create(&main_data->eat_count_thread, NULL,
				&eat_count_routine, main_data) != 0)
			return (join_threads(main_data, 2, 0));
	i = 0;
	while (i < main_data->num_philo)
	{
		if (pthread_create(main_data->philo_threads + i, NULL, &philo_routine,
				main_data->philos + i) != 0)
			return (join_threads(main_data, 3, i));
		i++;
	}
	return (1);
}

static int	join_threads(t_main_data *main_data, int other_threads,
		int num_philo_thread)
{
	int	i;

	i = 0;
	write_creating_threads_status(main_data, -1);
	if (other_threads >= 1)
		pthread_join(main_data->printer_thread, NULL);
	if (other_threads >= 2)
		pthread_join(main_data->philo_monitor_thread, NULL);
	if (other_threads >= 3 && main_data->min_times_eat >= 0)
		pthread_join(main_data->eat_count_thread, NULL);
	while (i < num_philo_thread)
	{
		pthread_join(main_data->philo_threads[i], NULL);
		i++;
	}
	return (free_all_data(main_data, 5));
}

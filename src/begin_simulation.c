/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:07:51 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/10 20:22:22 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// uneven takes right first
//  even takes left first
// philos and forks are clockwise

int	begin_simulation(t_main_data *main_data)
{
	int	i;
	int	status;

	status = pthread_create(&main_data->printer_threads, NULL, &msg_routine,
			main_data);
	i = 0;
	while (i < main_data->num_philo)
	{
		status = pthread_create(main_data->philo_threads + i, NULL,
				&philo_routine, main_data->philos + i);
		if (status != 0)
			return (error_creating_threads(main_data, i, i));
		status = pthread_create(main_data->philo_monitor_threads + i, NULL,
				&philo_monitor_routine, main_data->philos + i);
		if (status != 0)
			return (error_creating_threads(main_data, i, i - 1));
		i++;
	}
	if (gettimeofday(&main_data->sim_start, NULL) == -1)
		return (error_creating_threads(main_data, main_data->num_philo,
				main_data->num_philo));
	write_creating_threads_status(main_data, 1);
	i = 0;
	status = read_sim_status_main(main_data);
	while (status == RUNNING)
	{
		status = read_sim_status_main(main_data);
		usleep(1000);
	}
	i = 0;
	while (i < main_data->num_philo)
	{
		printf("checking\n");
		write_sim_status_philo(main_data->philos + i, status);
		i++;
	}
	i = 0;
	while (i < main_data->num_philo)
	{
		pthread_join(main_data->philo_threads[i], NULL);
		i++;
	}
	// print_main_data(main_data);
	return (free_all_data(main_data, 0));
}

int	error_creating_threads(t_main_data *main_data, int num_philo_thread,
		int num_monitoring_thread)
{
	int	i;

	i = 0;
	write_creating_threads_status(main_data, -1);
	while (i < num_philo_thread)
	{
		pthread_join(main_data->philo_threads[i], NULL);
		if (i < num_monitoring_thread)
			pthread_join(main_data->philo_monitor_threads[i], NULL);
		i++;
	}
	return (free_all_data(main_data, 5));
}

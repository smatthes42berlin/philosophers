/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:07:51 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/09 12:40:59 by smatthes         ###   ########.fr       */
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

	i = 0;
	while (i < main_data->num_philo)
	{
		status = pthread_create(main_data->philo_threads + i, NULL,
				&philo_routine, main_data->philos + i);
		if (status != 0)
			return (error_creating_threads(main_data, i));
		main_data->philos[i].thread_id = main_data->philo_threads[i];
		i++;
	}
	if (set_sim_start_time_all(main_data) == -1)
		return (error_creating_threads(main_data, main_data->num_philo));
	write_creating_threads_status(main_data, 1);
	i = 0;
	status = read_sim_status_main(main_data);
	while (status == RUNNING)
		status = read_sim_status_main(main_data);
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

int	error_creating_threads(t_main_data *main_data, int num_thread)
{
	int	i;

	i = 0;
	write_creating_threads_status(main_data, -1);
	while (i < num_thread)
	{
		pthread_join(main_data->philo_threads[i], NULL);
		i++;
	}
	return (free_all_data(main_data, 5));
}

int	set_sim_start_time_all(t_main_data *main_data)
{
	int i = 0;

	if (get_reference_time_stamp(main_data, &main_data->sim_start) == -1)
		return (-1);
	while (i < main_data->num_philo)
	{
		(main_data->philos)[i].last_eat = main_data->sim_start;
		i++;
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:01:42 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/08 14:05:29 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_main_data(t_main_data *main_data)
{
	main_data->num_eaten_min_times = 0;
	main_data->all_threads_created = FALSE;
	main_data->someone_died = FALSE;
	main_data->philo_threads = 0;
	main_data->error_during_sim = FALSE;
	if (gettimeofday(&main_data->reference_time, NULL) == -1)
		return (-1);
	main_data->philo_threads = malloc(sizeof(t_philo) * main_data->num_philo);
	if (!main_data->philo_threads)
		return (-1);
	if (pthread_mutex_init(&(main_data->all_threads_mutex), NULL) != 0)
	{
		free(main_data->philo_threads);
		return (-1);
	}
	if (pthread_mutex_init(&(main_data->print_mutex), NULL) != 0)
	{
		pthread_mutex_destroy(&(main_data->print_mutex));
		free(main_data->philo_threads);
		return (-1);
	}
	return (1);
}
int	init_philo_data(t_main_data *main_data)
{
	int	i;

	i = 0;
	main_data->philos = malloc(sizeof(t_philo) * main_data->num_philo);
	if (!main_data->philos)
		return (-1);
	while (i < main_data->num_philo)
	{
		main_data->philos[i].id = i;
		main_data->philos[i].thread_id = -1;
		main_data->philos[i].times_eaten = 0;
		main_data->philos[i].main_data = main_data;
		i++;
	}
	return (1);
}
int	init_fork_data(t_main_data *main_data)
{
	int	i;

	i = 0;
	main_data->forks = malloc(sizeof(t_philo) * main_data->num_philo);
	if (!main_data->forks)
		return (-1);
	while (i < main_data->num_philo)
	{
		main_data->forks[i].init_sucessful = FALSE;
		main_data->forks[i].on_table = TRUE;
		main_data->forks[i].id = i;
		if (pthread_mutex_init(&(main_data->forks[i].mutex), NULL) != 0)
			return (-1);
		main_data->forks[i].init_sucessful = TRUE;
		i++;
	}
	return (1);
}

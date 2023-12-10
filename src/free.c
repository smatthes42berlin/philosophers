/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:01:42 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/10 11:57:55 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_code_main_data(t_main_data *main_data, int code)
{
	free(main_data->philo_threads);
	pthread_mutex_destroy(&(main_data->all_threads_mutex));
	pthread_mutex_destroy(&(main_data->print_mutex));
	pthread_mutex_destroy(&(main_data->num_min_times_eat_mutex));
	pthread_mutex_destroy(&(main_data->sim_status_mutex));
	return (code);
}

int	free_code_forks(t_main_data *main_data, int code)
{
	int	i;

	i = 0;
	while (main_data->forks[i].init_sucess_table == TRUE)
	{
		pthread_mutex_destroy(&(main_data->forks[i].mutex_on_table));
		i++;
	}
	i = 0;
	while (main_data->forks[i].init_sucess_use == TRUE)
	{
		pthread_mutex_destroy(&(main_data->forks[i].mutex_in_use));
		i++;
	}
	free(main_data->forks);
	return (free_code_philos(main_data, code));
}

int	free_code_philos(t_main_data *main_data, int code)
{
	int	i;

	i = 0;
	while (main_data->philos[i].init_sucessful == TRUE)
	{
		pthread_mutex_destroy(&(main_data->philos[i].sim_status_mutex));
		i++;
	}
	free(main_data->philos);
	return (free_code_main_data(main_data, code));
}

int	free_all_data(t_main_data *main_data, int code)
{
	free_code_forks(main_data, code);
	return (code);
}

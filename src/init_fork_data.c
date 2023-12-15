/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fork_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:01:42 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/15 16:37:43 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_fork_data(t_main_data *main_data, int num_mutex_1, int num_mutex_2,
		int code)
{
	int	i;

	i = 0;
	while (i < main_data->num_philo)
	{
		if (i < num_mutex_1)
			pthread_mutex_destroy(&(main_data->forks[i].mutex_in_use));
		if (i < num_mutex_2)
			pthread_mutex_destroy(&(main_data->forks[i].mutex_on_table));
		i++;
	}
	free(main_data->forks);
	return (code);
}

int	init_fork_data(t_main_data *main_data)
{
	int	i;

	i = 0;
	main_data->forks = malloc(sizeof(t_philo) * main_data->num_philo);
	if (!main_data->forks)
		return (ERROR);
	while (i < main_data->num_philo)
	{
		main_data->forks[i].on_table = TRUE;
		main_data->forks[i].id = i;
		if (pthread_mutex_init(&(main_data->forks[i].mutex_in_use),
				NULL) != 0)
			return (free_fork_data(main_data, i, i, ERROR));
		if (pthread_mutex_init(&(main_data->forks[i].mutex_on_table),
				NULL) != 0)
			return (free_fork_data(main_data, i + 1, i, ERROR));
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:01:42 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/15 16:43:04 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_philo_data(t_main_data *main_data, int num_mutex_1, int num_mutex_2,
		int code)
{
	int	i;

	i = 0;
	while (i < main_data->num_philo)
	{
		if (i < num_mutex_1)
			pthread_mutex_destroy(&(main_data->philos[i].sim_status_mutex));
		if (i < num_mutex_2)
			pthread_mutex_destroy(&(main_data->philos[i].times_eaten_mutex));
		i++;
	}
	free(main_data->philos);
	return (code);
}

int	init_philo_data(t_main_data *main_data)
{
	int	i;

	i = 0;
	main_data->philos = malloc(sizeof(t_philo) * main_data->num_philo);
	if (!main_data->philos)
		return (ERROR);
	while (i < main_data->num_philo)
	{
		main_data->philos[i].id = i;
		main_data->philos[i].times_eaten = 0;
		main_data->philos[i].last_eat = 0;
		main_data->philos[i].sim_status = RUNNING;
		main_data->philos[i].main_data = main_data;
		if (pthread_mutex_init(&(main_data->philos[i].sim_status_mutex),
				NULL) != 0)
			return (free_philo_data(main_data, i, i, ERROR));
		if (pthread_mutex_init(&(main_data->philos[i].times_eaten_mutex),
				NULL) != 0)
			return (free_philo_data(main_data, i + 1, i, ERROR));
		i++;
	}
	return (1);
}

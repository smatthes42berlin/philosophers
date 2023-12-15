/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getset_min_times_eat.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:36:10 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/15 16:38:06 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	read_min_eat_main(t_main_data *main_data)
{
	int	val;

	pthread_mutex_lock(&main_data->num_min_times_eat_mutex);
	val = main_data->num_eaten_min_times;
	pthread_mutex_unlock(&main_data->num_min_times_eat_mutex);
	return (val);
}

void	increment_min_eat_main(t_main_data *main_data)
{
	pthread_mutex_lock(&main_data->num_min_times_eat_mutex);
	main_data->num_eaten_min_times++;
	pthread_mutex_unlock(&main_data->num_min_times_eat_mutex);
}

void	increment_min_eat_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->times_eaten_mutex);
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->times_eaten_mutex);
}

int	read_min_eat_philo(t_philo *philo)
{
	int	val;

	pthread_mutex_lock(&philo->times_eaten_mutex);
	val = philo->times_eaten;
	pthread_mutex_unlock(&philo->times_eaten_mutex);
	return (val);
}

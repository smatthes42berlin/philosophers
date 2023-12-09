/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_sim_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:36:10 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/09 11:16:06 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_sim_status_philo(t_philo *philo, int val)
{
	pthread_mutex_lock(&philo->sim_status_mutex);
	philo->sim_status = val;
	pthread_mutex_unlock(&philo->sim_status_mutex);
}

int	read_sim_status_philo(t_philo *philo)
{
	int	val;

	pthread_mutex_lock(&philo->sim_status_mutex);
	val = philo->sim_status;
	pthread_mutex_unlock(&philo->sim_status_mutex);
	return (val);
}

void	write_sim_status_main(t_main_data *main_data, int val)
{
	pthread_mutex_lock(&main_data->sim_status_mutex);
	main_data->sim_status = val;
	pthread_mutex_unlock(&main_data->sim_status_mutex);
}

int	read_sim_status_main(t_main_data *main_data)
{
	int val;

	pthread_mutex_lock(&main_data->sim_status_mutex);
	val = main_data->sim_status;
	pthread_mutex_unlock(&main_data->sim_status_mutex);

	return (val);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check_death.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:05:10 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/10 20:59:52 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo)
{
	LMICROSEC time_stamp;
	int status;

	pthread_mutex_lock(&philo->sim_status_mutex);
	status = get_time_stamp_us(philo->main_data, &time_stamp);
	if (status == ERROR)
		return (set_sim_error_philo(philo));
	// printf("%ld %ld\n", time_stamp - philo->last_eat,
	// 		philo->main_data->time_to_die);
	if (time_stamp - philo->last_eat >= philo->main_data->time_to_die)
	{
		philo_queue_msg(philo, DEAD);
		philo->sim_status = STOP;
	}
	pthread_mutex_unlock(&philo->sim_status_mutex);
	return (1);
}
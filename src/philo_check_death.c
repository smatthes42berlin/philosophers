/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check_death.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:05:10 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/15 16:39:29 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo)
{
	LMICROSEC	time_stamp;

	pthread_mutex_lock(&philo->sim_status_mutex);
	if (get_time_stamp_us(philo->main_data, &time_stamp) == ERROR)
		return (set_sim_error_philo(philo));
	if (time_stamp - philo->last_eat >= philo->main_data->time_to_die)
	{
		philo->sim_status = DEAD;
		write_sim_status_main(philo->main_data, DEAD);
		philo_queue_msg(philo, DEAD);
	}
	pthread_mutex_unlock(&philo->sim_status_mutex);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check_death.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:05:10 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/14 11:59:24 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo)
{
	LMICROSEC time_stamp;

	pthread_mutex_lock(&philo->sim_status_mutex);
	if (get_time_stamp_us(philo->main_data, &time_stamp) == ERROR)
		return (set_sim_error_philo(philo));
	if (time_stamp - philo->last_eat >= philo->main_data->time_to_die)
	{
		philo->sim_status = DEAD;
		write_sim_status_main(philo->main_data, DEAD);
		philo_queue_msg(philo, DEAD);
		if (read_fork_on_table(philo->fork_first) == FALSE)
			put_back_fork(philo->fork_first);
		if (read_fork_on_table(philo->fork_first) == TRUE)
			put_back_fork(philo->fork_second);
	}
	pthread_mutex_unlock(&philo->sim_status_mutex);
	return (1);
}
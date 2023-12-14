/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:07:51 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/14 12:11:00 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// uneven takes right first
//  even takes left first
// philos and forks are clockwise

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = data;
	if (ensure_all_threads_created(philo->main_data) == ERROR)
		return (NULL);
	while (read_sim_status_philo(philo) == RUNNING)
	{
		take_forks(philo);
		eat(philo);
		put_back_forks(philo);
		if (read_sim_status_philo(philo) != RUNNING)
			return (NULL);
		philo_sleep(philo);
		if (read_sim_status_philo(philo) != RUNNING)
			return (NULL);
		think(philo);
	}
	return (NULL);
}

int	take_forks(t_philo *philo)
{
	take_fork(philo->fork_first);
	philo_queue_msg(philo, TAKEFORK);
	take_fork(philo->fork_second);
	philo_queue_msg(philo, TAKEFORK);
	return (TRUE);
}

int	eat(t_philo *philo)
{
	int	status;

	pthread_mutex_lock(&philo->sim_status_mutex);
	status = get_time_stamp_us(philo->main_data, &philo->last_eat);
	pthread_mutex_unlock(&philo->sim_status_mutex);
	if (status == ERROR)
		return (set_sim_error_philo(philo));
	philo->times_eaten++;
	philo_queue_msg(philo, EATING);
	if (ft_sleep(philo, philo->main_data->time_to_eat) == ERROR)
		return (set_sim_error_philo(philo));
	return (TRUE);
}

int	put_back_forks(t_philo *philo)
{
	put_back_fork(philo->fork_first);
	put_back_fork(philo->fork_second);
	return (TRUE);
}

int	philo_sleep(t_philo *philo)
{
	philo_queue_msg(philo, SLEEPING);
	if (ft_sleep(philo, philo->main_data->time_to_sleep) == ERROR)
		return (set_sim_error_philo(philo));
	return (TRUE);
}

int	think(t_philo *philo)
{
	philo_queue_msg(philo, THINKING);
	usleep(philo->main_data->time_to_think);
	return (TRUE);
}

int	ft_sleep(t_philo *philo, LMICROSEC duration)
{
	if (usleep(duration) == -1)
		return (set_sim_error_philo(philo));
	return (1);
}

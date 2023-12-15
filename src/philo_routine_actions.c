/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_actions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:07:51 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/15 11:23:38 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	increment_min_eat_philo(philo);
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
	if (philo->main_data->time_to_think > 0 && ft_sleep(philo,
			philo->main_data->time_to_think) == ERROR)
		return (set_sim_error_philo(philo));
	return (TRUE);
}

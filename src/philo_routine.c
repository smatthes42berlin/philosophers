/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:07:51 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/09 13:06:29 by smatthes         ###   ########.fr       */
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
	if (ensure_all_philos_created(philo) == ERROR)
		return (NULL);
	get_reference_time_stamp(philo->main_data, &philo->temp_cur_time);
	printf("%ld Philo %d starts!\n", philo->temp_cur_time, philo->id);
	while (!do_exit_death_error(philo))
	{
		if (take_forks(philo) == ERROR)
			return (NULL);
		if (eat(philo) == ERROR)
			return (NULL);
		if (put_back_forks(philo) == ERROR)
			return (NULL);
		if (philo_sleep(philo) == ERROR)
			return (NULL);
		think(philo);
	}
	return (NULL);
}

int	put_back_forks(t_philo *philo)
{
	put_back_fork(philo->fork_first);
	printf("Philo %d put back first fork!\n", philo->id);
	if (do_exit_death_error(philo))
		return (ERROR);
	put_back_fork(philo->fork_second);
	printf("Philo %d put back second fork!\n", philo->id);
	return (TRUE);
}

int	think(t_philo *philo)
{
	printf("Philo %d is thinking!\n", philo->id);
	return (TRUE);
}

int	philo_sleep(t_philo *philo)
{
	if (ft_sleep(philo, philo->main_data->time_to_eat) == ERROR)
		return (ERROR);
	return (TRUE);
}

int	eat(t_philo *philo)
{
	if (get_reference_time_stamp(philo->main_data, &philo->last_eat) == ERROR)
		return (ERROR);
	printf("Philo %d is eating!\n", philo->id);
	philo->times_eaten++;
	// here: check if min times eaten is reached and than incremtn monitor variable
	if (ft_sleep(philo, philo->main_data->time_to_eat) == ERROR)
		return (ERROR);
	return (TRUE);
}

int	take_forks(t_philo *philo)
{
	// printf("Philo %d tries forks 1111111111!\n", philo->id);
	while (philo->fork_first->on_table == FALSE)
	{
		if (!do_exit_death_error(philo))
			return (ERROR);
	}
	take_fork(philo->fork_first);
	printf("Philo %d took first fork!\n", philo->id);
	while (philo->fork_second->on_table == FALSE)
	{
		if (!do_exit_death_error(philo))
			return (ERROR);
	}
	take_fork(philo->fork_second);
	printf("Philo %d took second fork!\n", philo->id);
	return (TRUE);
}

int	ft_sleep(t_philo *philo, LMICROSEC duration)
{
	LMICROSEC	time_slept;

	time_slept = 0;
	while (time_slept < duration && !do_exit_death_error(philo))
	{
		if (usleep(50) == -1)
			return (set_sim_error(philo->main_data));
		time_slept += 50;
	}
	if (duration >= time_slept)
		return (TRUE);
	return (ERROR);
}

BOOL	do_exit_death_error(t_philo *philo)
{
	BOOL	death_status;

	death_status = is_dead(philo);
	if (death_status)
		write_sim_status_main(philo->main_data, SOMEONEDIED);
	return (death_status || read_sim_status_main(philo->main_data) != RUNNING);
}

int	ensure_all_philos_created(t_philo *philo_data)
{
	int	thread_creation_status;

	thread_creation_status = 0;
	while (thread_creation_status == 0)
		thread_creation_status = read_creating_threads_status(philo_data->main_data);
	if (thread_creation_status == -1)
		return (-1);
	return (0);
	printf("Philo! %d\n", philo_data->id);
}

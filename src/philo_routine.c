/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:07:51 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/08 11:06:54 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// uneven takes right first
//  even takes left first
// philos and forks are clockwise

void	*philo_routine(void *data)
{
	t_philo	*philo_data;

	philo_data = data;
	if (ensure_all_philos_created(philo_data) == -1)
		return (NULL);
	// enter_philo_routine();
	// usleep(2000000);
	return (NULL);
}

// take fork according to odd or even
// take other fork (mutexed)
// eat checking death
// put back fork
// put back fork
// sleep checking death
// think
// try to eat again

int	ensure_all_philos_created(t_philo *philo_data)
{
	int thread_creation_status;

	thread_creation_status = 0;
	while (thread_creation_status == 0)
		thread_creation_status = read_creating_threads_status(philo_data->main_data);
	if (thread_creation_status == -1)
		return (-1);
	return (0);
	printf("Philo! %d\n", philo_data->id);
}
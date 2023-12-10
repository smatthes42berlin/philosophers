/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor_routine.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:07:51 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/10 21:07:11 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// uneven takes right first
//  even takes left first
// philos and forks are clockwise

void	*philo_monitor_routine(void *data)
{
	t_philo	*philo;

	philo = data;
	if (ensure_all_threads_created(philo) == ERROR)
		return (NULL);
	while (read_sim_status_philo(philo) == RUNNING)
	{
		check_death(philo);
		usleep(1000);
	}
	return (NULL);
}

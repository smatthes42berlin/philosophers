/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:07:51 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/18 14:00:24 by smatthes         ###   ########.fr       */
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
	if (philo->main_data->num_philo == 1)
	{
		philo_queue_msg(philo, TAKEFORK);
		return (NULL);
	}
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

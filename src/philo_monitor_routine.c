/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor_routine.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:07:51 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/14 19:48:10 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// uneven takes right first
//  even takes left first
// philos and forks are clockwise

static void	check_eaten_enough(t_philo *philo, BOOL *eaten_enough);

void	*philo_monitor_routine(void *data)
{
	t_philo	*philo;
	int		eaten_enough;

	philo = data;
	eaten_enough = FALSE;
	if (ensure_all_threads_created(philo->main_data) == ERROR)
		return (NULL);
	while (read_sim_status_philo(philo) == RUNNING)
	{
		check_death(philo);
		if (philo->main_data->min_times_eat >= 0 && !eaten_enough)
		{
			check_eaten_enough(philo, &eaten_enough);
		}
		usleep(1000);
	}
	return (NULL);
}

static void	check_eaten_enough(t_philo *philo, BOOL *eaten_enough)
{
	if (philo->times_eaten >= philo->main_data->min_times_eat)
	{
		increment_min_eat_main(philo->main_data);
		*eaten_enough = TRUE;
	}
}
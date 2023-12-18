/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor_routine.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:07:51 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/18 11:27:23 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// uneven takes right first
//  even takes left first
// philos and forks are clockwise

static void	check_eaten_enough(t_philo *philo, BOOL *eaten_enough);

void	*philo_monitor_routine(void *data)
{
	t_main_data	*main_data;
	int			eaten_enough;
	int			i;

	main_data = data;
	i = 0;
	if (ensure_all_threads_created(main_data) == ERROR)
		return (NULL);
	while (read_sim_status_main(main_data) == RUNNING)
	{
		while (i < main_data->num_philo)
		{
			check_death(main_data->philos + i);
			if (main_data->min_times_eat >= 0
				&& !main_data->philos[i].eaten_enough)
			{
				check_eaten_enough(main_data->philos + i, &eaten_enough);
			}
		}
	}
	return (NULL);
}

static void	check_eaten_enough(t_philo *philo, BOOL *eaten_enough)
{
	if (read_min_eat_philo(philo) >= philo->main_data->min_times_eat)
	{
		increment_min_eat_main(philo->main_data);
		*eaten_enough = TRUE;
	}
}

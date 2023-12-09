/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check_death.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:05:10 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/09 11:18:05 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

BOOL	is_dead(t_philo *philo)
{
	LMICROSEC ref_time_stamp;
	int status;

	status = get_reference_time_stamp(philo->main_data, &ref_time_stamp);
	if (status == ERROR)
		return (set_sim_error(philo->main_data));
	if (ref_time_stamp - philo->last_eat >= philo->main_data->time_to_die)
		return (TRUE);
	return (FALSE);
}
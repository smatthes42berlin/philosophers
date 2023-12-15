/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 08:18:37 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/15 11:55:07 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	ft_sleep(t_philo *philo, LMICROSEC duration)
// {
// 	if (usleep(duration) == -1)
// 		return (set_sim_error_philo(philo));
// 	return (1);
// }

int	ft_sleep(t_philo *philo, LMICROSEC duration)
{
	LMICROSEC	start_time;
	LMICROSEC	cur_time;

	if (get_time_stamp_us(philo->main_data, &start_time))
		return (ERROR);
	get_time_stamp_us(philo->main_data, &cur_time);
	while (cur_time < start_time + duration)
	{
		usleep(100);
		get_time_stamp_us(philo->main_data, &cur_time);
	}
	return (1);
}

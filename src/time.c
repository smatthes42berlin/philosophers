/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:06:10 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/10 20:56:38 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time_stamp_ms(t_main_data *main_data, LMICROSEC *ref_time_stamp)
{
	int	status;

	status = get_time_stamp_us(main_data, ref_time_stamp);
	*ref_time_stamp /= 1000;
	return (status);
}

int	get_time_stamp_us(t_main_data *main_data, LMICROSEC *ref_time_stamp)
{
	struct timeval	cur_time;

	if (gettimeofday(&cur_time, NULL) == -1)
		return (-1);
	*ref_time_stamp = cur_time.tv_sec - main_data->sim_start.tv_sec;
	*ref_time_stamp *= 1000000;
	*ref_time_stamp += cur_time.tv_usec;
	*ref_time_stamp -= main_data->sim_start.tv_usec;
	return (0);
}

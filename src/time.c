/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:06:10 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/08 14:35:11 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_reference_time_stamp(t_main_data *main_data, LMICROSEC *ref_time_stamp)
{
	struct timeval cur_time;

	if (gettimeofday(&cur_time, NULL) == -1)
		return (-1);
	printf("ref_time start sec = %ld\n", cur_time.tv_sec);
	printf("ref_time start micro sec = %ld\n",
			cur_time.tv_usec);
	*ref_time_stamp = cur_time.tv_sec - main_data->reference_time.tv_sec;
	*ref_time_stamp *= 1000000;
	*ref_time_stamp += cur_time.tv_usec;
	*ref_time_stamp -= main_data->reference_time.tv_usec;
	return (0);
}
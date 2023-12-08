/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:13:40 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/08 10:25:14 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void take_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
}

void put_back_fork(t_fork *fork)
{
	pthread_mutex_unlock(&fork->mutex);
}

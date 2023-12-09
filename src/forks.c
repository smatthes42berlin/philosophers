/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:13:40 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/09 13:09:56 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex_in_use);
	fork->on_table = FALSE;
}

void	put_back_fork(t_fork *fork)
{
	fork->on_table = TRUE;
	pthread_mutex_unlock(&fork->mutex_in_use);
}

// 

void	take_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex_in_use);
	fork->on_table = FALSE;
}

void	put_back_fork(t_fork *fork)
{
	fork->on_table = TRUE;
	pthread_mutex_unlock(&fork->mutex_in_use);
}



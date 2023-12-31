/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:13:40 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/14 11:09:38 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_fork *fork)
{
	write_fork_on_table(fork, FALSE);
	pthread_mutex_lock(&fork->mutex_in_use);
}

void	put_back_fork(t_fork *fork)
{
	write_fork_on_table(fork, TRUE);
	pthread_mutex_unlock(&fork->mutex_in_use);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getset_fork_on_table.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:36:10 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/15 16:41:06 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_fork_on_table(t_fork *fork, BOOL val)
{
	pthread_mutex_lock(&fork->mutex_on_table);
	fork->on_table = val;
	pthread_mutex_unlock(&fork->mutex_on_table);
}

BOOL	read_fork_on_table(t_fork *fork)
{
	int	val;

	pthread_mutex_lock(&fork->mutex_on_table);
	val = fork->on_table;
	pthread_mutex_unlock(&fork->mutex_on_table);
	return (val);
}

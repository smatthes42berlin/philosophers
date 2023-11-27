/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_forks_to_philos.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:01:42 by smatthes          #+#    #+#             */
/*   Updated: 2023/11/27 17:07:10 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	assign_forks_to_philos(t_gen_data *gen_data)
{
	int	i;
	int	index_last_philo;

	i = 1;
	index_last_philo = gen_data->num_philo - 1;
	if (gen_data->num_philo == 1)
	{
		gen_data->philos[i].left_fork = &(gen_data->forks[i]);
		gen_data->philos[i].right_fork = NULL;
		return ;
	}
	gen_data->philos[0].left_fork = &(gen_data->forks[0]);
	gen_data->philos[0].right_fork = &(gen_data->forks[index_last_philo]);
	while (i < gen_data->num_philo)
	{
		gen_data->philos[i].left_fork = &(gen_data->forks[i]);
		gen_data->philos[i].right_fork = &(gen_data->forks[i - 1]);
		i++;
	}
}

void	assign_philos_to_forks(t_gen_data *gen_data)
{
	int	i;
	int	index_last_philo;

	i = 0;
	index_last_philo = gen_data->num_philo - 1;
	while (i < gen_data->num_philo)
	{
		(gen_data->philos[i].left_fork)->right_philo = &(gen_data->philos[i]);
		(gen_data->philos[i].right_fork)->left_philo = &(gen_data->philos[i]);
		i++;
	}
}

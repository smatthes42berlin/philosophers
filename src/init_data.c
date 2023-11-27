/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:01:42 by smatthes          #+#    #+#             */
/*   Updated: 2023/11/27 16:36:15 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_gen_data(t_gen_data *gen_data)
{
	gen_data->simulation_start = 0;
}
int	init_philo_data(t_gen_data *gen_data)
{
	int	i;

	i = 0;
	gen_data->philos = malloc(sizeof(t_philo) * gen_data->num_philo);
	if (!gen_data->philos)
		return (-1);
	while (i < gen_data->num_philo)
	{
		gen_data->philos[i].id = i;
		i++;
	}
	return (1);
}
int	init_fork_data(t_gen_data *gen_data)
{
	int	i;

	i = 0;
	gen_data->forks = malloc(sizeof(t_philo) * gen_data->num_philo);
	if (!gen_data->forks)
		return (-1);
	while (i < gen_data->num_philo)
	{
		gen_data->forks[i].id = i;
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_forks_to_philos.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:01:42 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/07 13:55:31 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	assign_forks_to_philos(t_main_data *main_data)
{
	int	i;
	int	index_last_philo;

	i = 1;
	index_last_philo = main_data->num_philo - 1;
	if (main_data->num_philo == 1)
	{
		main_data->philos[i].left_fork = &(main_data->forks[i]);
		main_data->philos[i].right_fork = NULL;
		return ;
	}
	main_data->philos[0].left_fork = &(main_data->forks[0]);
	main_data->philos[0].right_fork = &(main_data->forks[index_last_philo]);
	while (i < main_data->num_philo)
	{
		main_data->philos[i].left_fork = &(main_data->forks[i]);
		main_data->philos[i].right_fork = &(main_data->forks[i - 1]);
		i++;
	}
}

void	assign_philos_to_forks(t_main_data *main_data)
{
	int	i;

	i = 0;
	while (i < main_data->num_philo)
	{
		(main_data->philos[i].left_fork)->right_philo = &(main_data->philos[i]);
		(main_data->philos[i].right_fork)->left_philo = &(main_data->philos[i]);
		i++;
	}
}

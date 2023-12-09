/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_forks_to_philos.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:01:42 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/09 12:26:50 by smatthes         ###   ########.fr       */
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
		main_data->philos[i].left_fork = &(main_data->forks[0]);
		main_data->philos[i].right_fork = &(main_data->forks[0]);
		main_data->philos[i].fork_first = main_data->philos[i].right_fork;
		main_data->philos[i].fork_second = main_data->philos[i].left_fork;
		return ;
	}
	main_data->philos[0].left_fork = &(main_data->forks[0]);
	main_data->philos[0].right_fork = &(main_data->forks[index_last_philo]);
	while (i < main_data->num_philo)
	{
		main_data->philos[i].left_fork = &(main_data->forks[i]);
		main_data->philos[i].right_fork = &(main_data->forks[i - 1]);
		if (i % 2 == 0)
			take_left_fork_first(&(main_data->philos[i]));
		else
			take_right_fork_first(&(main_data->philos[i]));
		i++;
	}
}

void	take_right_fork_first(t_philo *philo)
{
	philo->fork_first = philo->right_fork;
	philo->fork_second = philo->left_fork;
}

void	take_left_fork_first(t_philo *philo)
{
	philo->fork_first = philo->left_fork;
	philo->fork_second = philo->right_fork;
}

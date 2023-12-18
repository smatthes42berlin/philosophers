/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_forks_to_philos.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:01:42 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/18 13:29:41 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	assign_forks_first_philo(t_main_data *main_data);
static void	assign_same_fork_twice(t_main_data *main_data);
static void	take_right_fork_first(t_philo *philo);
static void	take_left_fork_first(t_philo *philo);

void	assign_forks_to_philos(t_main_data *main_data)
{
	int	i;

	i = 1;
	if (main_data->num_philo == 1)
		return (assign_same_fork_twice(main_data));
	assign_forks_first_philo(main_data);
	while (i < main_data->num_philo)
	{
		main_data->philos[i].left_fork = &(main_data->forks[i]);
		main_data->philos[i].right_fork = &(main_data->forks[i - 1]);
		if ((i + 1) % 2 == 0)
			take_left_fork_first(&(main_data->philos[i]));
		else
			take_right_fork_first(&(main_data->philos[i]));
		i++;
	}
}

static void	assign_forks_first_philo(t_main_data *main_data)
{
	main_data->philos[0].left_fork = &(main_data->forks[0]);
	main_data->philos[0].right_fork = &(main_data->forks[main_data->num_philo
			- 1]);
	main_data->philos[0].fork_second = main_data->philos[0].left_fork;
	main_data->philos[0].fork_first = main_data->philos[0].right_fork;
}

static void	assign_same_fork_twice(t_main_data *main_data)
{
	main_data->philos[0].left_fork = &(main_data->forks[0]);
	main_data->philos[0].right_fork = &(main_data->forks[0]);
	main_data->philos[0].fork_first = main_data->philos[0].right_fork;
	main_data->philos[0].fork_second = main_data->philos[0].left_fork;
}

static void	take_right_fork_first(t_philo *philo)
{
	philo->fork_first = philo->right_fork;
	philo->fork_second = philo->left_fork;
}

static void	take_left_fork_first(t_philo *philo)
{
	philo->fork_first = philo->left_fork;
	philo->fork_second = philo->right_fork;
}

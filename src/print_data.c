/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:07:51 by smatthes          #+#    #+#             */
/*   Updated: 2023/11/27 17:14:34 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_gen_data(t_gen_data *gen_data)
{
	int	i;

	printf("num_philo = %d\n", gen_data->num_philo);
	printf("time_to_die = %d\n", gen_data->time_to_die);
	printf("time_to_eat = %d\n", gen_data->time_to_eat);
	printf("time_to_sleep = %d\n", gen_data->time_to_sleep);
	printf("min_times_eat = %d\n", gen_data->min_times_eat);
	printf("simulation_start = %d\n", gen_data->simulation_start);
	i = 0;
	while (i < gen_data->num_philo)
	{
		print_philo(&(gen_data->philos[i]));
		print_fork(&(gen_data->forks[i]));
		i++;
	}
}

void	print_philo(t_philo *philo)
{
	printf("id = %d\n", philo->id);
	printf("threadid = %d\n", philo->thread_id);
	printf("left fork = %d\n", philo->left_fork->id);
	printf("right fork = %d\n", philo->right_fork->id);
}
void	print_fork(t_fork *fork)
{
	printf("id = %d\n", fork->id);
	printf("left philo = %d\n", fork->left_philo->id);
	printf("right philo = %d\n", fork->right_philo->id);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:07:51 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/08 14:34:08 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_main_data(t_main_data *main_data)
{
	int	i;

	printf("\n***********************main_data*********************\n");
	printf("num_philo = %d\n", main_data->num_philo);
	printf("time_to_die = %ld\n", main_data->time_to_die);
	printf("time_to_eat = %ld\n", main_data->time_to_eat);
	printf("time_to_sleep = %ld\n", main_data->time_to_sleep);
	printf("min_times_eat = %d\n", main_data->min_times_eat);
	printf("sim_start = %ld\n", main_data->sim_start);
	printf("ref_time start sec = %ld\n", main_data->reference_time.tv_sec);
	printf("ref_time start micro sec = %ld\n",
			main_data->reference_time.tv_usec);
	printf("someone_died = %d\n", main_data->someone_died);
	printf("all_threads_created = %d\n", main_data->all_threads_created);
	printf("error_during_sim = %d\n", main_data->error_during_sim);
	printf("num_eaten_min_times = %d\n", main_data->num_eaten_min_times);
	printf("\n***********************philos*********************\n");
	i = 0;
	while (i < main_data->num_philo)
	{
		printf("---------------philo\n");
		print_philo(&(main_data->philos[i]));
		// printf(">>>>>>>>>>>>>>>fork\n");
		// print_fork(&(main_data->forks[i]));
		i++;
	}
}

void	print_philo(t_philo *philo)
{
	printf("id = %d\n", philo->id);
	printf("threadid = %ld\n", philo->thread_id);
	printf("times eaten = %d\n", philo->times_eaten);
	printf("last eat = %ld\n", philo->last_eat);
	printf("left fork = %d\n", philo->left_fork->id);
	printf("right fork = %d\n", philo->right_fork->id);
	printf("main_data = %p\n", philo->main_data);
}

void	print_fork(t_fork *fork)
{
	printf("id = %d\n", fork->id);
	printf("on_table = %d\n", fork->on_table);
	printf("init_sucessful = %d\n", fork->init_sucessful);
	printf("left philo = %d\n", fork->left_philo->id);
	printf("right philo = %d\n", fork->right_philo->id);
}

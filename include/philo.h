/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:38:48 by smatthes          #+#    #+#             */
/*   Updated: 2023/11/27 17:12:59 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// # include <errno.h>
// # include <fcntl.h>
# include <stdio.h>
// # include <string.h>
// # include <sys/stat.h>
// # include <sys/types.h>
// # include <sys/wait.h>
// # include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_philo	t_philo;
typedef struct s_fork	t_fork;

typedef struct s_philo
{
	int					id;
	int					thread_id;
	t_fork				*left_fork;
	t_fork				*right_fork;
	pthread_mutex_t		mutex;
}						t_philo;

typedef struct s_fork
{
	int					id;
	t_philo				*left_philo;
	t_philo				*right_philo;
	pthread_mutex_t		mutex;
}						t_fork;

typedef struct s_gen_data
{
	int					num_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					min_times_eat;
	int					simulation_start;
	t_fork				*forks;
	t_philo				*philos;
}						t_gen_data;

int						ft_atoi_secure(const char *nptr, int *res);
int						ft_isspace(char c);
int						ft_isdigit(int c);
void					print_gen_data(t_gen_data *gen_data);
int						check_input(int argc, char *argv[],
							t_gen_data *gen_data);
void					init_gen_data(t_gen_data *gen_data);
int						init_philo_data(t_gen_data *gen_data);
int						init_fork_data(t_gen_data *gen_data);
int						free_code_philos(t_gen_data *gen_data, int code);
void					assign_forks_to_philos(t_gen_data *gen_data);
void					assign_philos_to_forks(t_gen_data *gen_data);
void					print_gen_data(t_gen_data *gen_data);
void					print_philo(t_philo *philo);
void					print_fork(t_fork *fork);

#endif
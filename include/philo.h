/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:38:48 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/08 14:24:36 by smatthes         ###   ########.fr       */
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
# include <limits.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

// 1 ms = 1000 micsec
# define DEATHCHECKMICSEC 1000
# define BOOL int
# define TRUE 1
# define FALSE 0
# define LMICROSEC long

typedef struct s_philo		t_philo;
typedef struct s_fork		t_fork;
typedef struct s_main_data	t_main_data;

typedef struct s_philo
{
	int						id;
	pthread_t				thread_id;
	int						times_eaten;
	LMICROSEC				last_eat;
	t_fork					*left_fork;
	t_fork					*right_fork;
	t_main_data				*main_data;
	pthread_mutex_t			mutex;
}							t_philo;

typedef struct s_fork
{
	int						id;
	BOOL					on_table;
	BOOL					init_sucessful;
	t_philo					*left_philo;
	t_philo					*right_philo;
	pthread_mutex_t			mutex;
}							t_fork;

typedef struct s_main_data
{
	int						num_philo;
	int						min_times_eat;
	int						num_eaten_min_times;
	LMICROSEC				time_to_die;
	LMICROSEC				time_to_eat;
	LMICROSEC				time_to_sleep;
	BOOL					someone_died;
	BOOL					all_threads_created;
	BOOL					error_during_sim;
	LMICROSEC				sim_start;
	struct timeval			reference_time;
	pthread_mutex_t			all_threads_mutex;
	pthread_mutex_t			print_mutex;
	t_fork					*forks;
	t_philo					*philos;
	pthread_t				*philo_threads;
}							t_main_data;

/* input checking */
int							ft_atoi_secure(const char *nptr, long *res);
int							ft_atoi_secure_int(const char *nptr, int *res);
int							ft_isspace(char c);
int							ft_isdigit(int c);
int							check_input(int argc, char *argv[],
								t_main_data *main_data);
void						print_main_data(t_main_data *main_data);
void						print_philo(t_philo *philo);
void						print_fork(t_fork *fork);

/* init data */
int							init_main_data(t_main_data *main_data);
int							init_philo_data(t_main_data *main_data);
int							init_fork_data(t_main_data *main_data);
void						assign_forks_to_philos(t_main_data *main_data);
void						assign_philos_to_forks(t_main_data *main_data);

/* free data */
int							free_code_philos(t_main_data *main_data, int code);
int							free_all_data(t_main_data *main_data, int code);
int	free_code_main_data(t_main_data *main_data,
						int code);
int	error_creating_threads(t_main_data *main_data,
							int num_thread);
int	free_code_forks(t_main_data *main_data,
					int code);

/* philo routine */
void						*philo_routine(void *data);
int							begin_simulation(t_main_data *main_data);
void						take_fork(t_fork *fork);
void						put_back_fork(t_fork *fork);
int							set_sim_start_time_all(t_main_data *main_data);
int							ensure_all_philos_created(t_philo *philo_data);
int	get_reference_time_stamp(t_main_data *main_data,
								LMICROSEC *ref_time_stamp);

/* mutexed access functions */
void	write_creating_threads_status(t_main_data *main_data,
									BOOL val);
BOOL						read_creating_threads_status(t_main_data *main_data);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:38:48 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/10 21:14:11 by smatthes         ###   ########.fr       */
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
# define ERROR -1
# define RUNNING 0
# define STOP 1

# define TAKEFORK 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DEAD 5
# define EATENENOUGH 6

# define MAX_MESSAGES 1000

typedef struct s_philo		t_philo;
typedef struct s_fork		t_fork;
typedef struct s_main_data	t_main_data;

typedef struct s_message
{
	LMICROSEC				timestamp;
	int						philo_id;
	int						msg_type;
}							t_message;

typedef struct s_message_queue
{
	t_message				messages[MAX_MESSAGES];
	int						front;
	int						rear;
	int						count;
	pthread_mutex_t			mutex;
}							t_message_queue;

typedef struct s_philo
{
	int						id;
	pthread_t				thread_id;
	int						times_eaten;
	LMICROSEC				last_eat;
	LMICROSEC				temp_cur_time;
	t_fork					*left_fork;
	t_fork					*right_fork;
	t_fork					*fork_first;
	t_fork					*fork_second;
	t_main_data				*main_data;
	int						sim_status;
	pthread_mutex_t			sim_status_mutex;
	BOOL					init_sucessful;
}							t_philo;

typedef struct s_fork
{
	int						id;
	BOOL					on_table;
	BOOL					init_sucess_table;
	BOOL					init_sucess_use;
	pthread_mutex_t			mutex_in_use;
	pthread_mutex_t			mutex_on_table;
}							t_fork;

typedef struct s_main_data
{
	int						num_philo;
	int						min_times_eat;
	int						num_eaten_min_times;
	LMICROSEC				time_to_die;
	LMICROSEC				time_to_eat;
	LMICROSEC				time_to_sleep;
	LMICROSEC				time_to_think;
	BOOL					all_threads_created;
	BOOL					stop_printing;
	struct timeval			sim_start;
	int						sim_status;
	int						msg_status;
	t_message_queue			msg_queue_1;
	t_message_queue			msg_queue_2;
	t_message_queue			*collect_msg_queue;
	t_message_queue			*print_msg_queue;
	pthread_mutex_t			all_threads_mutex;
	pthread_mutex_t			print_mutex;
	pthread_mutex_t			num_min_times_eat_mutex;
	pthread_mutex_t			sim_status_mutex;
	t_fork					*forks;
	t_philo					*philos;
	pthread_t				*philo_threads;
	pthread_t				*philo_monitor_threads;
	pthread_t				printer_threads;
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
void						take_right_fork_first(t_philo *philo);
void						take_left_fork_first(t_philo *philo);

/* free data */
int							free_code_philos(t_main_data *main_data, int code);
int							free_all_data(t_main_data *main_data, int code);
int	free_code_main_data(t_main_data *main_data,
						int code);
int	error_creating_threads(t_main_data *main_data,
							int num_philo_thread,
							int num_monitoring_thread);
int	free_code_forks(t_main_data *main_data,
					int code);

/* philo routine */
void						*philo_routine(void *data);
int							begin_simulation(t_main_data *main_data);
void						take_fork(t_fork *fork);
void						put_back_fork(t_fork *fork);
int							ensure_all_threads_created(t_philo *philo_data);
int							get_time_stamp_ms(t_main_data *main_data,
								LMICROSEC *ref_time_stamp);
int							get_time_stamp_us(t_main_data *main_data,
								LMICROSEC *ref_time_stamp);
int							check_death(t_philo *philo);
int							set_sim_error(t_main_data *main_data);
int							set_sim_error_philo(t_philo *philo);
int							put_back_forks(t_philo *philo);
int							think(t_philo *philo);
int							philo_sleep(t_philo *philo);
int							eat(t_philo *philo);
int							take_forks(t_philo *philo);
int							ft_sleep(t_philo *philo, LMICROSEC duration);
BOOL						do_exit_death_error(t_philo *philo);
int							print_message(t_philo *philo, int action);
void						*philo_monitor_routine(void *data);

/* mutexed access functions */
void	write_creating_threads_status(t_main_data *main_data,
									BOOL val);
BOOL						read_creating_threads_status(t_main_data *main_data);
void						write_sim_status_philo(t_philo *philo, int val);
int							read_sim_status_philo(t_philo *philo);
void	write_sim_status_main(t_main_data *main_data,
							int val);
int							read_sim_status_main(t_main_data *main_data);
void						write_fork_on_table(t_fork *fork, BOOL val);
BOOL						read_fork_on_table(t_fork *fork);

/* messaging */

int							init_queue(t_message_queue *msg_queue);
void						reset_queue(t_message_queue *msg_queue);
void						enqueue(t_message_queue *msg_queue, t_message msg);
t_message					dequeue(t_message_queue *msg_queue);
void						swap_queues(t_main_data *main_data);
void	print_msg_queue(t_main_data *main_data,
						t_message_queue *msg_queue);
int							philo_queue_msg(t_philo *philo, int msg_type);
void						*msg_routine(void *data);

#endif
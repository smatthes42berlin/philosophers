/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:05:18 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/08 11:20:53 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LIMIT 100000000
#define NUMTHREADS 2

void	*routine(void *ptr)
{
	pthread_mutex_t	*mutex;

	mutex = ptr;
	pthread_mutex_lock(mutex);
	printf("locked\n");
	usleep(2000000);
	pthread_mutex_unlock(mutex);
	return (NULL);
}

int	main(void)
{
	int				i;
	pthread_mutex_t	mutex;

	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, routine, &mutex);
	pthread_create(&thread2, NULL, routine, &mutex);
	pthread_mutex_init(&mutex, NULL);
	i = 0;
	pthread_mutex_destroy(&mutex);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	exit(1);
}

// void	*routine(void *arg)
// {
// 	int			*fds;
// 	pthread_t	t;

// 	fds = (int *)arg;
// 	t = pthread_self();
// 	usleep((rand() / (1.0 + RAND_MAX)) * 1000000);
// 	write(fds[1], &t, sizeof(t));
// 	return (NULL);
// }

// int	main(void)
// {
// 	int fds[NUMTHREADS];
// 	srand(time(0));
// 	pipe(fds);
// 	for (int i = 0; i < NUMTHREADS; i++)
// 	{
// 		pthread_t tid;
// 		pthread_create(&tid, NULL, routine, fds);
// 		printf("created: %llu\n\n", (unsigned long long)tid);
// 	}
// 	// for (int i = 0; i < NUMTHREADS; i++)
// 	// {
// 	// 	pthread_t tid;
// 	// 	read(fds[0], &tid, sizeof(tid));
// 	// 	printf("joining: %llu\n\n", (unsigned long long)tid);
// 	// 	pthread_join(tid, 0);
// 	// }
// 	pthread_exit(0);
// }
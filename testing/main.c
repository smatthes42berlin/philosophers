/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:05:18 by smatthes          #+#    #+#             */
/*   Updated: 2023/11/26 10:05:11 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LIMIT 100000000
#define NUMTHREADS 2

void	*routine(void *)
{
	int			i;
	pthread_t	t;

	t = pthread_self();
	i = 0;
	while (i < LIMIT)
	{
		i++;
	}
	printf("Thread  ended %lu!\n", t);
	return (NULL);
}

int	main(void)
{
	int				i;
	pthread_t		th[NUMTHREADS];
	pthread_mutex_t	mutex;

	i = 0;
	pthread_mutex_init(&mutex, NULL);
	while (i < NUMTHREADS)
	{
		if (pthread_create(th + i, NULL, &routine, NULL) != 0)
			return (1);
		// pthread_detach(*(th + i));
		printf("Thread %lu started!\n", th[i]);
		i++;
	}
	i = 0;
	// while (i < NUMTHREADS)
	// {
	// 	if (pthread_join(th[i], NULL) != 0)
	// 		return (2);
	// 	// printf("Thread %d ended!\n", i);
	// 	i++;
	// }
	pthread_mutex_destroy(&mutex);
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
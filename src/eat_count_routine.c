/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_count_routine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:13:40 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/14 19:47:59 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static BOOL	check_eat_count_reached(t_main_data *main_data);

void	*eat_count_routine(void *data)
{
	t_main_data	*main_data;

	main_data = data;
	if (ensure_all_threads_created(main_data) == ERROR)
		return (NULL);
	while (read_sim_status_main(main_data) == RUNNING)
	{
		if (check_eat_count_reached(main_data))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

static BOOL	check_eat_count_reached(t_main_data *main_data)
{
	int eat_count;

	eat_count = read_min_eat_main(main_data);
	if (eat_count >= main_data->num_philo)
	{
		write_sim_status_main(main_data, EATENENOUGH);
		philo_queue_msg(main_data->philos, EATENENOUGH);
		return (TRUE);
	}
	return (FALSE);
}
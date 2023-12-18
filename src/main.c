/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:07:51 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/18 11:23:48 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// uneven takes right first
//  even takes left first
// philos and forks are clockwise

int	main(int argc, char *argv[])
{
	t_main_data	main_data;

	if (check_input(argc, argv, &main_data) == -1)
		return (1);
	if (init_main_data(&main_data) == -1)
		return (2);
	if (init_philo_data(&main_data) == -1)
		return (free_main_data(&main_data, 7, 3));
	if (init_fork_data(&main_data) == -1)
		return (free_err_forks(&main_data, 4));
	assign_forks_to_philos(&main_data);
	return (begin_simulation(&main_data));
}

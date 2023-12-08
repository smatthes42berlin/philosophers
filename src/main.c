/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:07:51 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/08 10:56:42 by smatthes         ###   ########.fr       */
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
		return (free_code_main_data(&main_data, 3));
	if (init_fork_data(&main_data) == -1)
		free_code_forks(&main_data, 4);
	assign_forks_to_philos(&main_data);
	assign_philos_to_forks(&main_data);
	// print_main_data(&main_data);
	// return (free_all_data(&main_data, 0));
	// free(main_data.forks);
	// free(main_data.philos);
	// return (1);
	return (begin_simulation(&main_data));
}

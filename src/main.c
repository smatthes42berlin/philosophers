/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:07:51 by smatthes          #+#    #+#             */
/*   Updated: 2023/11/27 17:13:04 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// uneven takes right first
//  even takes left first
// philos and forks are clockwise

int	main(int argc, char *argv[])
{
	t_gen_data	gen_data;

	if (check_input(argc, argv, &gen_data) == -1)
		return (-1);
	init_gen_data(&gen_data);
	if (init_philo_data(&gen_data) == -1)
		return (-2);
	if (init_fork_data(&gen_data) == -1)
		free_code_philos(&gen_data, -3);
	assign_forks_to_philos(&gen_data);
	print_gen_data(&gen_data);
	// initilise_philos();
	return (0);
}

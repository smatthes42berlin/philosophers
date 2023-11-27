/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:01:42 by smatthes          #+#    #+#             */
/*   Updated: 2023/11/27 16:08:41 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	print_error_message_code(const char *message, int code);

int	check_input(int argc, char *argv[], t_gen_data *gen_data)
{
	int	status;

	if (argc > 6 || argc < 5)
		return (-1);
	status = ft_atoi_secure(argv[1], &(gen_data->num_philo));
	if (gen_data->num_philo < 1 || gen_data->num_philo > 1000)
		return (print_error_message_code("philo num range error", -1));
	status = ft_atoi_secure(argv[2], &(gen_data->time_to_die));
	if (gen_data->time_to_die < 0 || status == -1)
		return (print_error_message_code("time to die range error", -1));
	status = ft_atoi_secure(argv[3], &(gen_data->time_to_eat));
	if (gen_data->time_to_eat < 0 || status == -1)
		return (print_error_message_code("time to eat range error", -1));
	status = ft_atoi_secure(argv[4], &(gen_data->time_to_sleep));
	if (gen_data->time_to_sleep < 0 || status == -1)
		return (print_error_message_code("time to sleep range error", -1));
	if (argc == 6)
	{
		status = ft_atoi_secure(argv[5], &(gen_data->min_times_eat));
		if (gen_data->min_times_eat < 0 || status == -1)
			return (print_error_message_code("min times eat range error", -1));
	}
	else
		gen_data->min_times_eat = -1;
	return (1);
}

static int	print_error_message_code(const char *message, int code)
{
	printf("%s\n", message);
	return (code);
}

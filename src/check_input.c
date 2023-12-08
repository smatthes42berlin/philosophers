/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:01:42 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/08 14:25:24 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	print_error_message_code(const char *message, int code);
static int	print_error_usage(int code);
static int	convert_to_microseconds(t_main_data *main_data);

int	check_input(int argc, char *argv[], t_main_data *main_data)
{
	int	status;

	if (argc > 6 || argc < 5)
		return (print_error_usage(-1));
	status = ft_atoi_secure_int(argv[1], &(main_data->num_philo));
	if (main_data->num_philo < 1 || main_data->num_philo > 1000)
		return (print_error_message_code("philo num range error", -1));
	status = ft_atoi_secure(argv[2], &(main_data->time_to_die));
	if (main_data->time_to_die < 0 || status == -1)
		return (print_error_message_code("time to die range error", -1));
	status = ft_atoi_secure(argv[3], &(main_data->time_to_eat));
	if (main_data->time_to_eat < 0 || status == -1)
		return (print_error_message_code("time to eat range error", -1));
	status = ft_atoi_secure(argv[4], &(main_data->time_to_sleep));
	if (main_data->time_to_sleep < 0 || status == -1)
		return (print_error_message_code("time to sleep range error", -1));
	if (argc == 6)
	{
		status = ft_atoi_secure_int(argv[5], &(main_data->min_times_eat));
		if (main_data->min_times_eat < 0 || status == -1)
			return (print_error_message_code("min times eat range error", -1));
	}
	else
		main_data->min_times_eat = -1;
	return (convert_to_microseconds(main_data));
}

static int	convert_to_microseconds(t_main_data *main_data)
{
	long	temp;

	temp = main_data->time_to_die;
	main_data->time_to_die = temp * 1000;
	temp = main_data->time_to_eat;
	main_data->time_to_eat = temp * 1000;
	temp = main_data->time_to_sleep;
	main_data->time_to_sleep = temp * 1000;
	return (1);
}

static int	print_error_message_code(const char *message, int code)
{
	printf("%s\n", message);
	return (code);
}

static int	print_error_usage(int code)
{
	printf("usage: ");
	printf("./philo ");
	printf("number_of_philosophers ");
	printf("time_to_die ");
	printf("time_to_eat ");
	printf("time_to_sleep ");
	printf("[number_of_times_each_philosopher_must_eat]\n");
	return (code);
}

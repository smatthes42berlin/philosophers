/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:01:42 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/18 11:23:44 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_all_data(t_main_data *main_data, int code)
{
	free_fork_data(main_data, main_data->num_philo, main_data->num_philo, code);
	free_philo_data(main_data, main_data->num_philo, main_data->num_philo,
		code);
	free_main_data(main_data, 7, code);
	(main_data->sim_status)++;
	return (code);
}

int	free_err_forks(t_main_data *main_data, int code)
{
	free_main_data(main_data, 7, code);
	free_philo_data(main_data, main_data->num_philo, main_data->num_philo,
		code);
	return (code);
}

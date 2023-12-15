/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ensure_all_threads_created.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:07:51 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/15 08:57:22 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ensure_all_threads_created(t_main_data *main_data)
{
	int	thread_creation_status;

	thread_creation_status = 0;
	while (thread_creation_status == 0)
		thread_creation_status = read_creating_threads_status(main_data);
	if (thread_creation_status == -1)
		return (ERROR);
	return (0);
}

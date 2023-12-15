/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:11:29 by smatthes          #+#    #+#             */
/*   Updated: 2023/12/15 16:43:32 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_sim_error_philo(t_philo *philo)
{
	write_sim_status_philo(philo, ERROR);
	return (ERROR);
}

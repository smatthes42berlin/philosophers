/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_secure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 09:52:03 by smatthes          #+#    #+#             */
/*   Updated: 2023/11/27 15:49:24 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_strlen_1_to_9(const char *int_str);
static int	handle_to_many_dig(const char *nptr, int sign, long *res);
static int	set_res_return_code(int *res, int num, int error_code);

int	ft_atoi_secure(const char *nptr, int *res)
{
	int		sign;
	long	res_help;
	int		i;

	i = 0;
	sign = 1;
	res_help = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	if (!handle_to_many_dig(&nptr[i], sign, &res_help))
		return (set_res_return_code(res, res_help, -1));
	while (ft_isdigit(nptr[i]) != 0)
		res_help = res_help * 10 + nptr[i++] - '0';
	res_help = res_help * sign;
	if (res_help > INT_MAX)
		return (set_res_return_code(res, INT_MAX, -1));
	if (res_help < INT_MIN)
		return (set_res_return_code(res, INT_MIN, -1));
	return (set_res_return_code(res, res_help, 1));
}

static int	handle_to_many_dig(const char *nptr, int sign, long *res)
{
	int	len;

	len = ft_strlen_1_to_9(nptr);
	if (len > 11 && sign > 0)
	{
		*res = INT_MAX;
		return (0);
	}
	if (len > 11 && sign < 0)
	{
		*res = INT_MIN;
		return (0);
	}
	return (1);
}

static int	ft_strlen_1_to_9(const char *int_str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!ft_isdigit(int_str[i]))
		return (0);
	while (int_str[i])
	{
		if (!ft_isdigit(int_str[i]))
			return (0);
		if (ft_isdigit(int_str[i]) && int_str[i] != '0')
			break ;
		i++;
	}
	while (int_str[i] && ft_isdigit(int_str[i]))
	{
		i++;
		len++;
	}
	return (len);
}

static int	set_res_return_code(int *res, int num, int error_code)
{
	*res = num;
	return (error_code);
}

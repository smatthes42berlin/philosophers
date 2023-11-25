/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:05:18 by smatthes          #+#    #+#             */
/*   Updated: 2023/11/15 10:03:16 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// if single quotes, remove them
// dont apply split, until last single quote is found

int	main(int argc, char *argv[], char *envp[])
{
	int fd[2];
	int status = 0;

	char *arr[] = {"awk", "-F", "someword", "{count++} END {print count}", NULL};
	execve("/usr/bin/awk", arr, envp);
}
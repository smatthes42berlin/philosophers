/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:38:48 by smatthes          #+#    #+#             */
/*   Updated: 2023/11/12 16:55:54 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "lib_main.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex_data
{
	int		fd_pipe[2];
	char	*infile;
	char	*outfile;
	int		child_1_pid;
	int		child_2_pid;
	char	**envp;
	char	*cmd_str_1;
	char	**cmd_arg_1;
	char	*exec_path_1;
	char	*exec_path_2;
	char	*cmd_str_2;
	char	**cmd_arg_2;
	char	**path;
}			t_pipex_data;

/* handle args */

int			handle_args(t_pipex_data *data, int argc, char *argv[],
				char *envp[]);

/* process cmd1 */

void		process_cmd1(t_pipex_data *data);

/* process cmd2 */

void		process_cmd2(t_pipex_data *data);

/* process main */

void		process_main(t_pipex_data *data);

/* utils */

int			split_cmd_args(char *cmd_args_str, char ***cmd_args_arr);
int			get_path(char *envp[], char ***cmd_args_arr);
void		print_pipex_data(t_pipex_data *data);
int			check_cmd_access(t_pipex_data *data, char **cmd_arg,
				char **exec_path);

/* free */

int			free_cmd_arg1(t_pipex_data *data);
int			free_cmd_arg1_2(t_pipex_data *data);
int			free_args_handling_status(t_pipex_data *data, int status);
int			free_args_handling(t_pipex_data *data);
int			free_cmd_arg1_2_path(t_pipex_data *data);

/* exit */

void		clean_exit_error(t_pipex_data *data, int code, char *message);
void		clean_exit_127(t_pipex_data *data, char *cmd);
void		clean_exit_main(t_pipex_data *data, int code);

#endif
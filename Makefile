# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 14:58:39 by smatthes          #+#    #+#              #
#    Updated: 2023/12/14 20:09:27 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $^ -> all prerequisites with spaces in between
# $@ -> filename of the target of the rule
# $< ->  name of the first prerequisite
# $(info $(ADDHEADERLOC))


# -I Flag adds path where header files are searched during preprocessing
SHELL:=/bin/bash
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread $(INCLUDEFLAGS) 
NAME = philo
LINK= cc
CC = cc

INCLUDEPATH = ./include/
INCLUDEFLAGS = $(patsubst %,-I% ,$(INCLUDEPATH))
SUBFOLDERSRC = .
BASEPATHSRC = ./src/
PATHSRC = $(patsubst %,$(BASEPATHSRC)%,$(SUBFOLDERSRC))
PATHBUILD = build/
PATHOBJ = build/obj/

VPATH = $(PATHSRC) $(INCLUDEPATH)

SRC = 	main.c \
		check_input.c \
		ft_atoi_secure_util.c \
		ft_atoi_secure.c \
		init_main_data.c \
		init_philo_data.c \
		init_fork_data.c \
		free.c \
		assign_forks_to_philos.c \
		msg_queue_print.c \
		msg_queue_init.c \
		msg_queue_actions.c \
		print_data.c \
		begin_simulation.c \
		philo_routine.c \
		philo_monitor_routine.c \
		msg_routine.c \
		eat_count_routine.c \
		forks.c \
		time.c \
		getset_sim_status.c \
		getset_fork_on_table.c \
		getset_creating_threads.c \
		getset_min_times_eat.c \
		error.c \
		philo_check_death.c \
		philo_queue_msg.c \
		ensure_all_threads_created.c

OBJFNAME = $(SRC:.c=.o)
OBJ = $(patsubst %,$(PATHOBJ)%,$(OBJFNAME))

.PHONY: all clean fclean re  

all: $(NAME)

$(NAME): $(OBJ)
	$(LINK) $(CFLAGS) -o $(NAME) $(OBJ) 

$(PATHOBJ)%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PRECIOUS: $(PATHOBJ)%.o

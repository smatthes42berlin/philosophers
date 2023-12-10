# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 14:58:39 by smatthes          #+#    #+#              #
#    Updated: 2023/12/10 20:26:54 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $^ -> all prerequisites with spaces in between
# $@ -> filename of the target of the rule
# $< ->  name of the first prerequisite
# $(info $(ADDHEADERLOC))


# -I Flag adds path where header files are searched during preprocessing
SHELL:=/bin/bash
CFLAGS = -Wall -Wextra -Werror $(INCLUDEFLAGS) 
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
		free.c \
		init_data.c \
		assign_forks_to_philos.c \
		print_data.c \
		begin_simulation.c \
		philo_routine.c \
		mutex_creating_threads.c \
		forks.c \
		time.c \
		mutex_sim_status.c \
		error.c \
		philo_check_death.c \
		mutex_fork_on_table.c \
		msg_queue_print.c \
		msg_queue.c \
		philo_queue_msg.c \
		msg_routine.c \
		philo_monitor_routine.c  

		
		
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

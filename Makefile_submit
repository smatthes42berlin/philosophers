# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_submit                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 14:58:39 by smatthes          #+#    #+#              #
#    Updated: 2023/10/29 13:36:56 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $^ -> all prerequisites with spaces in between
# $@ -> filename of the target of the rule
# $< ->  name of the first prerequisite

SHELL:=/bin/bash
CFLAGS = -Wall -Wextra -Werror $(INCLUDEFLAGS) 
NAME = fdf
NAMELIBFT = libft.a
NAMELIBMLX = libmlx.a
NAMEADDLIBS = -lmlx -lXext -lX11
NAMEMATH = -lm
LINK= cc
CC = cc

PATHLIBFT = ./libft/
PATHLIBMLX = ./minilibx-linux/
PATHADDLIBS = /usr/include/
INCLUDEPATH = . ./libft/ ./minilibx-linux/ /usr/include/
INCLUDEFLAGS = $(patsubst %,-I% ,$(INCLUDEPATH))

VPATH = $(PATHSRC) $(INCLUDEPATH)

SRC = 	main.c \
		check_input_main.c \
		parse_map_main.c \
		parse_map_check_dimensions.c \
		parse_map_get_points.c \
		free_all_points.c \
		print_points.c \
		project_points_main.c \
		parse_map_utils.c \
		calc_points_color_main.c \
		colors.c \
		get_points_range.c \
		show_main.c \
		show_free.c \
		show_draw_main.c \
		show_draw_calc_coords.c \
		show_draw_lines.c \
		show_bresenham.c \
		show_bresenham_utils.c \
		show_events.c

		
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re libs norm

$(NAME): libs $(OBJ)
	$(LINK) $(CFLAGS) -o $(NAME) $(OBJ) -L$(PATHLIBFT) -lft -L$(PATHLIBMLX) -lmlx -L$(PATHADDLIBS) $(NAMEADDLIBS) $(NAMEMATH)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libs:
	make -C $(PATHLIBFT)
	make -C $(PATHLIBMLX)

clean:
	make -C $(PATHLIBFT) clean
	make -C $(PATHLIBMLX) clean
	$(RM) $(OBJ)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean all

norm:
	clear
	@printf "\n*****************libft source files*****************\n\n"
	@norminette $(PATHLIBFT)*.c
	@printf "\n*****************libft header files*****************\n\n"
	@norminette -R CheckDefine $(PATHLIBFT)*.h
	@printf "\n*****************fdf source files*****************\n\n"
	@norminette *.c
	@printf "\n*****************fdf header files*****************\n\n"
	@norminette -R CheckDefine *.h
	@printf "\n"

getmaps:
	wget https://cdn.intra.42.fr/document/document/21662/maps.zip
	unzip maps.zip
	rm -rf maps.zip




.PRECIOUS: %.o
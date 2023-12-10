# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 15:02:54 by smatthes          #+#    #+#              #
#    Updated: 2023/12/10 21:16:56 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

clear


# number_philo=100
# time_to_die=500
# time_to_eat=200
# time_to_sleep=100
# number_min_eat=


# if [ $# -eq 0 ]; then
#     make && ./philo $number_philo $time_to_die $time_to_eat $time_to_sleep $number_min_eat
# else
#     # make && valgrind --tool=helgrind ./philo $number_philo $time_to_die $time_to_eat $time_to_sleep $number_min_eat
#     make && valgrind ./philo $number_philo $time_to_die $time_to_eat $time_to_sleep $number_min_eat
# fi

# tests from eval
make

# should not eat and die
# ./philo 1 800 200 200

# noone should die
./philo 5 800 200 200

# noone should die and sim should stop when every philo ate 7 times
# ./philo 1 800 200 200 7

# noone should die
# ./philo 4 410 200 200

# one should die
# ./philo 4 310 200 100

# 2 philo and check with different times, max dceath delay 10ms
# ./philo 1 800 200 200

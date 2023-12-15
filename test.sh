# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 15:02:54 by smatthes          #+#    #+#              #
#    Updated: 2023/12/15 15:55:37 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



number_philo=200
time_to_die=310
time_to_eat=100
time_to_sleep=100
number_min_eat=

make re
clear


# if [ $# -eq 0 ]; then
#     ./philo $number_philo $time_to_die $time_to_eat $time_to_sleep $number_min_eat
# else
#     # make && valgrind --tool=helgrind ./philo $number_philo $time_to_die $time_to_eat $time_to_sleep $number_min_eat
#     valgrind ./philo $number_philo $time_to_die $time_to_eat $time_to_sleep $number_min_eat
# fi

# tests from eval
# make

# should not eat and die
# ./philo 1 800 200 200

# noone should die
# ./philo 3 800 200 200

# noone should die and sim should stop when every philo ate 7 times
# ./philo 5 800 200 200 7

# noone should die
# valgrind --tool=helgrind ./philo 2 310 200 60

# guy on slack inly lost 9ms here (1000 philo 210 100 100) (10009)
# ./philo 200 600 100 100

# one should die
# ./philo 50 600 200 100

# 2 philo and check with different times, max dceath delay 10ms
# valgrind ./philo 4 610 200 100

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 15:02:54 by smatthes          #+#    #+#              #
#    Updated: 2023/12/09 13:03:27 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

clear


number_philo=2
time_to_die=1000
time_to_eat=100
time_to_sleep=100
number_min_eat=


if [ $# -eq 0 ]; then
    make && ./philo $number_philo $time_to_die $time_to_eat $time_to_sleep $number_min_eat
else
    # make && valgrind --tool=helgrind ./philo $number_philo $time_to_die $time_to_eat $time_to_sleep $number_min_eat
    make && valgrind ./philo $number_philo $time_to_die $time_to_eat $time_to_sleep $number_min_eat
fi
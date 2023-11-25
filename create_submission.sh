#!/bin/bash

clear

rm -rf submission
mkdir submission
mkdir submission/libft
mkdir submission/minilibx-linux

find ./libft/src -name \*.c -exec cp {} submission/libft \;
find ./libft/include -name \*.h -exec cp {} submission/libft \;
cp ./libft/Makefile_submit ./submission/libft/Makefile
cp ./libft/Makefile_src ./submission/libft/Makefile_src

find ./minilibx-linux/ -name \* -exec cp -r {} submission/minilibx-linux \;


find ./src -name \*.c -exec cp {} submission/ \;
find ./include -name \*.h -exec cp {} submission/ \;
cp ./Makefile_submit ./submission/Makefile

# cp -r ./test_program/ submission/

# cd ./submission/test_program/
# bash ./main.sh
pwd
# rm -rf ./test_program

# rm -rf test_program

# make -C submission/libft/ all
# make -C submission/libft/ clean
# make -C submission/libft/ re
# make -C submission/libft/ fclean
# make -C submission/libft/ all
# make -C submission/libft/ all

# make -C submission/ all
# make submission/clean
# make -C submission/ re
# make submission/fclean
# make -C submission/ all
# make -C submission/ all


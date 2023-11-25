# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 15:02:54 by smatthes          #+#    #+#              #
#    Updated: 2023/11/12 13:31:19 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

clear

infile="infile.txt"
cmd1="cat -b -A"
cmd2="grep e"
outfile="outfile.txt"

outfile_control="outfile_control.txt"

rm $outfile

if [ $# -eq 0 ]; then
    make && ./pipex $infile "$cmd1" "$cmd2" $outfile
else
    make && valgrind ./pipex $infile "$cmd1" "$cmd2" $outfile
fi

printf "< $infile $cmd1 | $cmd2 > $outfile_control\n"
printf "./pipex $infile '$cmd1' '$cmd2' $outfile\n"

< $infile $cmd1 | $cmd2 > $outfile_control  


printf "\n\n"
cat $outfile
printf "\n\n\n"
cat $outfile_control
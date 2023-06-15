#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ps_tester.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anammal <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/11 02:45:11 by anammal           #+#    #+#              #
#    Updated: 2023/06/11 02:45:16 by anammal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

if [ "$#" -eq 0 ] || ! [[ $1 =~ ^[0-9]+$ ]] || ! [[ ${2:-1} =~ ^[0-9]+$ ]] || [ $1 -lt 2 ]; then
    echo "USAGE: $0 [input size] [number of tests] args must be digits!"
    echo -e "\t[input size] must be > 3"
    echo -e "\t[number of tests] to run N tests; 1 if not specified"
    exit 1
fi
input_size=$1
num_tests=${2:-1}
GREEN='\033[0;32m'
RED='\033[0;31m'
WBG='\033[47m'
NC='\033[0m'
if [ "$(ls checker 2>&1)" == "checker" ]; then
    CHECKER="./checker"
else
    if [ "$(uname)" == "Linux" ]; then
        CHECKER="./tool/checker_linux"
    else
        CHECKER="./tool/checker_Mac"
    fi
fi
echo -e "${WBG}test\tInput\tmoves\tChecker\tExec time\tMem leak${NC}"
for ((i = 1; i <= num_tests; i++)); do
    ARG=$(ruby -e "puts (((-($input_size / 2)))..(($input_size / 2 - 1))).to_a.shuffle.join(' ')")
    moves=$(./push_swap $ARG 2>&1 | wc -l | tr -d ' ')
    checker_output=$(./push_swap $ARG 2>&1 | $CHECKER $ARG 2>&1)
    exec_time=$((time ./push_swap $ARG 2>&1) 2>&1 | grep real | cut -d 'm' -f2)
    leak_output=$(valgrind --leak-check=full ./push_swap $ARG 2>&1 >/dev/null)
    leak_bytes=$(echo "$leak_output" | grep "definitely lost:" | awk '{print $4}')
    if [[ -z $leak_bytes ]]; then
        leak_bytes=0
    fi
    color_code=$RED
    if [[ "$checker_output" == "OK" ]] &&
        (( $(bc <<< "${exec_time%*s} < 0.050") )) &&
        [[ "$leak_bytes" == "0" ]] &&
        { [[ $input_size -eq 2 && $moves -lt 2 ]] ||
        [[ $input_size -eq 3 && $moves -lt 3 ]] ||
        [[ $input_size -eq 5 && $moves -lt 13 ]] ||
        [[ $input_size -eq 100 && $moves -lt 701 ]] ||
        [[ $input_size -eq 500 && $moves -lt 5501 ]]; }; then
        color_code=$GREEN
    fi
    echo -e "${i}>\t${color_code}$input_size\t$moves\t$checker_output\t$exec_time\t\t$leak_bytes${NC}"
done

if [ "$CHECKER" == "./checker" ]; then
    ./checker_tester.sh
fi

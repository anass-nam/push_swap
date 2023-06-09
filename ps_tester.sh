#!/bin/bash

if [ "$#" -eq 0 ] || ! [[ $1 =~ ^[0-9]+$ ]] || ! [[ ${2:-1} =~ ^[0-9]+$ ]] || [ $1 -lt 2 ]; then
    echo "USAGE: $0 [input size] [number of tests] args must be digits!"
    echo -e "\t[input size] must be > 3"
    echo -e "\t[number of tests] to run N tests; 1 if not specified"
    exit 1
fi

input_size=$1
num_tests=${2:-1}


if [ "$(uname)" == "Linux" ]; then
    CHECKER="./tool/checker_linux"
else
    CHECKER="./tool/checker_Mac"
fi

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

echo -e "test\tInput\tmoves\tChecker\tExec time\tMem leak"

for ((i = 1; i <= num_tests; i++)); do
    ARG=$(ruby -e "puts (((-($input_size / 2)))..(($input_size / 2 - 1))).to_a.shuffle.join(' ')")
    moves=$(./push_swap $ARG | wc -l)
    checker_output=$(./push_swap $ARG | $CHECKER $ARG)
    exec_time=$((time ./push_swap $ARG) 2>&1 | grep real | cut -d 'm' -f2)
    leak_output=$(valgrind --leak-check=full ./push_swap $ARG 2>&1 >/dev/null)
    leak_bytes=$(echo "$leak_output" | grep "definitely lost:" | awk '{print $4}')
    if [[ -z $leak_bytes ]]; then
        leak_bytes=0
    fi
    color_code=$RED

    if [[ "$checker_output" == "OK" ]] &&
        (( $(bc <<< "${exec_time%*s} < 0.030") )) &&
        [[ "$leak_bytes" == "0" ]] &&
        { [[ $input_size -eq 3 && $moves -lt 3 ]] ||
        [[ $input_size -eq 5 && $moves -lt 13 ]] ||
        [[ $input_size -le 100 && $moves -lt 701 ]] ||
        [[ $input_size -le 500 && $moves -lt 5500 ]]; }; then
        color_code=$GREEN
    fi





    echo -e "${i}>\t${color_code}$input_size\t$moves\t$checker_output\t$exec_time\t\t$leak_bytes${NC}"
done



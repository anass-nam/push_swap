#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
WBG='\033[47m'
NC='\033[0m'

check_args() {
    local arg=$1
    local chkr=$(./push_swap $arg 2>&1 | ./tool/checker_linux $arg 2>&1)
    local mychkr=$(./push_swap $arg 2>&1 | ./checker $arg 2>&1)
    local color_code=$RED

    if [[ "$chkr" == "" ]]; then
        chkr="Null"
    fi

    if [[ "$mychkr" == "" ]]; then
        mychkr="Null"
    fi

    if [[ "$chkr" == "$mychkr" ]]; then
        color_code=$GREEN
    fi

    echo -e "${WBG}$2\t${NC}=>\tchecker: ${color_code}$chkr${NC}\t|\tmy checker: ${color_code}$mychkr${NC}"
}

# already sorted
ARG="1 2 3"
check_args "$ARG" "Already sorted"

# already sorted
ARG="-333 -33 -3 -1 0 1 2 3 45 346 23456 23468"
check_args "$ARG" "Already sorted"

# 3 not sorted
ARG=$(ruby -e "puts (-1..1).to_a.shuffle.join(' ')")
check_args "$ARG" "3 Not sorted"

# 5 not sorted
ARG=$(ruby -e "puts (-2..2).to_a.shuffle.join(' ')")
check_args "$ARG" "5 Not sorted"

# 100 not sorted
ARG=$(ruby -e "puts (-50..49).to_a.shuffle.join(' ')")
check_args "$ARG" "100 Not sorted"

# 500 not sorted
ARG=$(ruby -e "puts (-250..249).to_a.shuffle.join(' ')")
check_args "$ARG" "500 Not sorted"

# invalid args case
ARG="1 2, 3"
check_args "$ARG" "Invalid args"

# duplicated args case
ARG="1 2 3 1"
check_args "$ARG" "Duplicated args"

# no args case
check_args "" "No args\t"

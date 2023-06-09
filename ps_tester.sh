#!/bin/bash




echo -e "\tInput\tmoves\tExec time"


i=0
while (( ++i <= $1 )); do
	ARG=`ruby -e "puts (-1..1).to_a.shuffle.join(' ')"`; echo  -e "\t3 \t$(./push_swap $ARG | wc -l) \t$((time ./push_swap $ARG) 2>&1 | grep real | cut -d 'm' -f2)"
done
echo ""
i=0
while (( ++i <= $1 )); do
	ARG=`ruby -e "puts (-2..2).to_a.shuffle.join(' ')"`; echo  -e "\t5 \t$(./push_swap $ARG | wc -l) \t$((time ./push_swap $ARG) 2>&1 | grep real | cut -d 'm' -f2)"
done
echo ""
i=0
while (( ++i <= $1 )); do
	ARG=`ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`; echo  -e "\t100 \t$(./push_swap $ARG | wc -l) \t$((time ./push_swap $ARG) 2>&1 | grep real | cut -d 'm' -f2)"
done
echo ""
i=0
while (( ++i <= $1 )); do
	ARG=`ruby -e "puts (-250..249).to_a.shuffle.join(' ')"`; echo  -e "\t500 \t$(./push_swap $ARG | wc -l) \t$((time ./push_swap $ARG) 2>&1 | grep real | cut -d 'm' -f2)"
done

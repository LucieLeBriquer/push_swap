#!/bin/bash

tests=100
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m'

function test()
{
    sum=0
    max=0
    min=2147483647
	tot_error=0
    for i in `seq 0 $tests`;
    do
		entries=$(shuf -i 0-10000 -n $1)
        nb_ope=$(./push_swap $entries | wc -l)
        sum=$(($sum + $nb_ope))
		error=$(./push_swap $entries | ./checker $entries | grep -E "(KO|Error)" | wc -l)
		tot_error=$(($tot_error + $error))
        if [ "$nb_ope" -lt "$min" ]
        then
            min=$nb_ope
        fi
        if [ "$nb_ope" -gt "$max" ]
        then
            max=$nb_ope
        fi
    done

    X=`echo "$sum / $tests" | bc`
	if [ "$error" -eq "0" ]
	then
		printf "${GREEN}[OK]${NC}"
	else
		printf "${RED}[KO]${NC}"
	fi
	printf "\t$1\t${BLUE}$X${NC}\t${PURPLE}$max${NC}\t${CYAN}$min${NC}\n"
}

printf "\tnbs\tavg.\tmax\tmin\n\n"
for arg in $@
do
    test $arg
done
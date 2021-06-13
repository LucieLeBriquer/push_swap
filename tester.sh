#!/bin/bash

tests=200
RED='\033[0;31m'
GREEN='\033[0;32m'
COLOR='\033[0;33m'
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
		error=$(./push_swap $entries | ./checker $entries | grep KO | wc -l)
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
	printf "$1\t${COLOR}$X${NC}\t${RED}$max${NC}\t${GREEN}$min${NC}"
	if [ "$error" -eq "0" ]
	then
		printf "\t\t${GREEN}[OK]${NC}\n\n"
	else
		printf "\t\t${RED}[KO]${NC}\n\n"
	fi
}

printf "nbs\tavg.\tmax\tmin\n\n"
for arg in $@
do
    test $arg
done
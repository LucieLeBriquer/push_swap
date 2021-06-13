#!/bin/bash

tests=10
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
		if [ "$valgrind" -eq "1" ]
		then
			error=$(valgrind -q ./push_swap $entries | ./checker $entries | grep -E "(KO|Error)" | wc -l)
		else
			error=$(./push_swap $entries | ./checker $entries | grep -E "(KO|Error)" | wc -l)
		fi
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

valgrind=0
for arg in $@
do
	if [ $arg = "-v" ]
	then
    	valgrind=1
	fi
done

if [ "$valgrind" -eq "1" ]
then
	tests=10
	printf "$tests tests per argument, also checking leaks\n\n"
else
	tests=100
	printf "$tests tests per argument, not checking leaks\n\n"
fi

re='^[0-9]+$'

printf "\tnbs\tavg.\tmax\tmin\n"
for arg in $@
do
	if [ $arg != "-v" ]
	then
		if [[ $arg =~ $re ]]
		then
    		test $arg $valgrind
		fi
	fi
done
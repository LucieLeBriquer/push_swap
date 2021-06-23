#!/bin/bash

CHECKER_PATH=./checker
PUSHSWAP_PATH=./push_swap

## colors

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m'

## check if checker and push_swap files are here

pushswap_ok=$(ls $PUSHSWAP_PATH 2>/dev/null | wc -l)
if [ "$pushswap_ok" -eq "0" ]
then
	printf "push_swap needed, please update PUSHSWAP_PATH\n"
	exit 0
fi

checker_ok=$(ls $CHECKER_PATH 2>/dev/null | wc -l)
if [ "$checker_ok" -eq "0" ]
then
	printf "checker needed, please update CHECKER_PATH\n"
	exit 0
fi

## generate random numbers

UNAME=$(uname -s)

function random_entry()
{
	if [ $UNAME == "Darwin" ]
	then
		entries=$(jot -r $1 0 10000)
	else
		entries=$(shuf -i 0-10000 -n $1)
	fi
}

## test function

function test()
{
    sum=0
    max=0
    min=2147483647
	tot_error=0
	leaks=0
    for i in `seq 1 $tests`;
    do
		random_entry $1
        nb_ope=$($PUSHSWAP_PATH $entries | wc -l)
        sum=$(($sum + $nb_ope))
		if [ "$valgrind" -eq "1" ]
		then
			error=$(valgrind $PUSHSWAP_PATH $entries 2> .valgrind_log | $CHECKER_PATH $entries | grep -E "(KO|Error)" | wc -l)
			leak=$(cat .valgrind_log | grep "LEAK" | wc -l)
			leaks=$(($leaks + $leak))
			rm .valgrind_log
		else
			error=$($PUSHSWAP_PATH $entries | $CHECKER_PATH $entries | grep -E "(KO|Error)" | wc -l)
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
	printf "\t$1\t${BLUE}%-d${NC}\t${PURPLE}%-d${NC}\t${CYAN}%-d${NC}" $X $max $min
	if [ "$valgrind" -eq "1" ]
	then
		if [ "$leaks" -eq "0" ]
		then
			printf "\t${GREEN}OK${NC}\n"
		else
			printf "\t${RED}KO${NC}\n"
		fi
	else
		printf "\n"
	fi
}

## valgrind option

valgrind=0
for arg in $@
do
	if [ $arg = "-v" ]
	then
    	valgrind=1
	fi
done

## title

if [ "$valgrind" -eq "1" ]
then
	tests=10
	printf "$tests tests per argument, also checking leaks\n\n"
	printf "\tnbs\tavg.\tmax\tmin\tleaks\n"
else
	tests=100
	printf "$tests tests per argument, not checking leaks\n\n"
	printf "\tnbs\tavg.\tmax\tmin\n"
fi

## main

re='^[0-9]+$'

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

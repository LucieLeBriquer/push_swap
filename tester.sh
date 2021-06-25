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

## help

function display_help()
{
	printf "usage:\t./tester.sh [options] n0 n1 n2 ...\n"
	printf "\twhere n0,n1,n2 are several sizes of input\n\n"
	printf "options:\n"
	printf "\t-v --valgrind\trun with valgrind to check leaks and errors\n"
	printf "\t-h --help\tdisplay this help\n\n"
	printf "example:\n\t./tester.sh 3 5 100 500\n"
	exit
}

if [ "$#" -eq "0" ]
then
	display_help
fi

## check if checker and push_swap files are here

pushswap_ok=$(ls $PUSHSWAP_PATH 2>/dev/null | wc -l)
if [ "$pushswap_ok" -eq "0" ]
then
	printf "push_swap needed, please update PUSHSWAP_PATH\n"
	exit
fi

checker_ok=$(ls $CHECKER_PATH 2>/dev/null | wc -l)
if [ "$checker_ok" -eq "0" ]
then
	printf "checker needed, please update CHECKER_PATH\n"
	exit
fi

## standard tests
fail=0

function test_error()
{
	test=$($VALGRIND$1 2> .log 1> .res ; cat .log | grep "Error" | wc -l)
	leak=$(cat .log | grep "LEAK" | wc -l)
	rm .log .res
	if [ "$test" -ne "$2" ]
	then
		printf "  ${RED}[KO]${NC} $cmd\n"
		fail=1
	else
		if [ "$leak" -ne "0" ]
		then
			printf "  ${YELLOW}[KO]${NC} $cmd\n"
		else
			printf "  ${GREEN}[OK]${NC} $cmd\n"
		fi
	fi
}

function standard_test_errors()
{
	printf "[TESTING ERRORS]\n"
	printf "$PUSHSWAP_PATH\n"

	cmd="$PUSHSWAP_PATH 0 2 one 3"
	test_error "$cmd" 1
	cmd="$PUSHSWAP_PATH -2147483648"
	test_error "$cmd" 0
	cmd="$PUSHSWAP_PATH -2147483649"
	test_error "$cmd" 1
	cmd="$PUSHSWAP_PATH 2147483647"
	test_error "$cmd" 0
	cmd="$PUSHSWAP_PATH 2147483648"
	test_error "$cmd" 1
	cmd="$PUSHSWAP_PATH 0 1 2 3 0"
	test_error "$cmd" 1

	test=$($VALGRIND$PUSHSWAP_PATH "0 1" "3 2 -1" 2> .log 1> .res ; cat .log | grep "Error" | wc -l)
	leak=$(cat .log | grep "LEAK" | wc -l)
	rm .log .res
	if [ "$test" -ne "0" ]
	then
		printf "  ${RED}[KO]${NC} $PUSHSWAP_PATH \"0 1\" \"3 2 -1\"\n"
		fail=1
	elif [ "$leak" -ne "0" ]
	then
		printf "  ${YELLOW}[KO]${NC} $PUSHSWAP_PATH \"0 1\" \"3 2 -1\"\n"
	else
		printf "  ${GREEN}[OK]${NC} $PUSHSWAP_PATH \"0 1\" \"3 2 -1\"\n"
	fi

	test=$($VALGRIND$PUSHSWAP_PATH "0 1" "3 2 0" 2> .log 1> .res ; cat .log | grep "Error" | wc -l)
	leak=$(cat .log | grep "LEAK" | wc -l)
	rm .log .res
	if [ "$test" -ne "1" ]
	then
		printf "  ${RED}[KO]${NC} $PUSHSWAP_PATH \"0 1\" \"3 2 0\"\n"
		fail=1
	elif [ "$leak" -ne "0" ]
	then
		printf "  ${YELLOW}[KO]${NC} $PUSHSWAP_PATH \"0 1\" \"3 2 0\"\n"
	else
		printf "  ${GREEN}[OK]${NC} $PUSHSWAP_PATH \"0 1\" \"3 2 0\"\n"
	fi

	printf "$CHECKER_PATH\n"

	cmd="$CHECKER_PATH 0 2 one 3"
	test_error "$cmd" 1
	cmd="$CHECKER_PATH -2147483649"
	test_error "$cmd" 1
	cmd="$CHECKER_PATH 2147483648"
	test_error "$cmd" 1
	cmd="$CHECKER_PATH 0 1 2 3 0"
	test_error "$cmd" 1

	test=$(echo notacommand | $VALGRIND$CHECKER_PATH 0 1 3 2 2> .log 1> .res ; cat .log | grep "Error" | wc -l)
	leak=$(cat .log | grep "LEAK" | wc -l)
	rm .log .res
	if [ "$test" -ne "1" ]
	then
		printf "  ${RED}[KO]${NC} echo notacommand | $CHECKER_PATH 0 1 3 2\n"
		fail=1
	elif [ "$leak" -ne "0" ]
	then
		printf "  ${YELLOW}[KO]${NC} echo notacommand | $CHECKER_PATH 0 1 3 2\n"
	else
		printf "  ${GREEN}[OK]${NC} echo notacommand | $CHECKER_PATH 0 1 3 2\n"
	fi

	test=$($VALGRIND$CHECKER_PATH "0 1" "3 2 0" 2> .log 1> .res ; cat .log | grep "Error" | wc -l)
	leak=$(cat .log | grep "LEAK" | wc -l)
	rm .log .res
	if [ "$test" -ne "1" ]
	then
		printf "  ${RED}[KO]${NC} $CHECKER_PATH \"0 1\" \"3 2 0\"\n"
		fail=1
	elif [ "$leak" -ne "0" ]
	then
		printf "  ${YELLOW}[KO]${NC} $CHECKER_PATH \"0 1\" \"3 2 0\"\n"
	else
		printf "  ${GREEN}[OK]${NC} $CHECKER_PATH \"0 1\" \"3 2 0\"\n"
	fi
	
	if [ "$fail" -ne "0" ]
	then
		exit
	fi
}

## generate random numbers

UNAME=$(uname -s)

function random_entry()
{
	if [ $UNAME == "Darwin" ]
	then
		entries=$(jot -r $1 0 10000 | tr '\n' ' ')
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
	errors_valgrind=0
	leaks=0
    for i in `seq 1 $tests`;
    do
		random_entry $1
        nb_ope=$($PUSHSWAP_PATH $entries | wc -l)
        sum=$(($sum + $nb_ope))
		error=$($VALGRIND$PUSHSWAP_PATH $entries 2> .log | $VALGRIND$CHECKER_PATH $entries 2>> .log 1>>.log ; cat .log | grep -E "(KO|Error)" | wc -l)
		leak=$(cat .log | grep "LEAK" | wc -l)
		error_valgrind=$(cat .log | grep "ERROR SUMMARY" | cut -d':' -f2 | cut -d'e' -f1 | cut -d' ' -f2)
		leaks=$(($leaks + $leak))
		if [ "$errors_valgrind" -ne "0" ]
		then
			errors_valgrind=$(($errors_valgrind + 1))
		fi
		rm .log
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
			printf "\t${GREEN}OK${NC}"
		else
			printf "\t${RED}KO${NC}"
		fi
		if [ "$errors_valgrind" -eq "0" ]
		then
			printf "\t${GREEN}0${NC}\n"
		else
			printf "\t${RED}$errors_valgrind${NC}\n"
		fi
	else
		printf "\n"
	fi
}

## options

valgrind=0
help=0
for arg in $@
do
	if [[ $arg = "-v" ||  $arg = "--valgrind" ]]
	then
    	valgrind=1
	fi
	if [[ $arg = "-h" ||  $arg = "--help" ]]
	then
		help=1
	fi
done

if [ "$help" -eq "1" ]
then
	display_help
fi

valgrind_exists=$(whereis valgrind | cut -d':' -f2 | wc -c)
if [[ "$valgrind" -eq "1" && "$valgrind_exists" -ne "1" ]]
then
	VALGRIND="valgrind "
else
	VALGRIND=""
fi

## title

title_printed=0
function print_title()
{
	if [ "$title_printed" -ne "0" ]
	then
		return
	fi
	title_printed=1
	printf "\n\n[STATISTICS]\n"
	if [ "$valgrind" -eq "1" ]
	then
		tests=10
		printf "$tests tests per argument, also checking leaks\n\n"
		printf "\tsize\tavg.\tmax\tmin\tleaks\terr\n"
	else
		tests=100
		printf "$tests tests per argument, not checking leaks\n\n"
		printf "\tsize\tavg.\tmax\tmin\n"
	fi
}

## main

re='^[0-9]+$'

standard_test_errors
for arg in $@
do
	if [[ $arg =~ $re ]]
	then
		print_title
   		test $arg $valgrind
	fi
done

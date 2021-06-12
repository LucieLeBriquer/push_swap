#!/bin/bash

tests=200

function test()
{
    sum=0;
    max=0
    min=2147483647
    printf ">> For $1 numbers\n"
    for i in `seq 0 $tests`;
    do
		entries=$(shuf -i 0-10000 -n $1)
        nb_ope=$(./push_swap $entries | wc -l)
        sum=$(($sum + $nb_ope))
        if [ "$nb_ope" -lt "$min" ]
        then
            min=$nb_ope
        fi
        if [ "$nb_ope" -gt "$max" ]
        then
            max=$nb_ope
        fi
    done

    printf "average : "
    X=`echo "$sum / $tests" | bc`
	echo -n $X
    printf "\nmax : $max\nmin : $min\n\n"
}

for arg in $@
do
    test $arg
done
# push_swap

## Description
This project consists in sorting data using two stacks and a limited set of instructions. The aim is to generate the smallest sequence of instructions that will sort the input data.

## Makefile
Run `make` to compile the `push_swap` program.
Run `make bonus` to compile the `checker` program.
Run `make full` to compile both of them.

## My push_swap tester
Here is a script to check both `push_swap` and `checker` programs. It provides the average/minimum/maximum number of moves for random inputs of a given size. It also checks if errors are handled. You can also check for memory leaks using `-v`.
```
usage: ./tester.sh [options] n0 n1 n2 ...
        where n0,n1,n2 are several sizes of input

options:
        -v --valgrind   run with valgrind to check leaks and errors
        -h --help       display this help

example: ./tester.sh 3 5 100 500
```

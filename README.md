# push_swap

## Description
This project consists in sorting data using two stacks and a limited set of instructions. The aim is to generate the smallest sequence of instructions that will sort the input data.

## Notation scale
<center>

| Input size | Max | 5pts | 4pts | 3pts | 2pts | 1pts |
| :----: |:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|
| 3    	 |  3    |   -   |   -   |   -   |   -   |   -   |
| 5   	 | 12    |   -   |   -   |   -   |   -   |   -   |
| 100    | 1500  |  700  |  900  | 1100  | 1300  | 1500  |
| 500    | 11500 |  5500 |  7000 |  8500 | 10000 | 11500 |

</center>

## Makefile
- Run `make` to compile the `push_swap` program.
- Run `make bonus` to compile the `checker` program.
- Run `make full` to compile both of them.

## My push_swap tester
I also wrote a script `tester.sh` to check both `push_swap` and `checker` programs. It provides the average/minimum/maximum number of moves for random inputs of a given size. It also checks if errors are handled. You can also check for memory leaks using `-v`.
```
usage:  ./tester.sh [options] n0 n1 n2 ...
        where n0,n1,n2 are several sizes of input

options:
        -v --valgrind   run with valgrind to check leaks and errors
        -h --help       display this help

example:
        ./tester.sh 3 5 100 500
```

## My results

```
[STATISTICS]
100 tests per argument, not checking leaks

        size    avg.    max     min
[OK]    3       1       2       0
[OK]    5       8       11      4
[OK]    100     687     746     643
[OK]    500     6065    6365    5738
```
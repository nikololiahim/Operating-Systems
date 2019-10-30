#!/usr/bin/bash
gcc ex1.c -o ex1
for ((c = 1; c <= $1; c++))
do  
	echo "Launch #$c"
	./ex1
done

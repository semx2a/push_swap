#!/bin/bash

while 1; do
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
	./push_swap $ARG
done
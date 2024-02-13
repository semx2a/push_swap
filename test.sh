#!/bin/bash

RESET="\033[0m"
bold=$(tput bold)
normal=$(tput sgr0)
BONUS=false

function test {
	while sleep 2; do
		ARG=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`
		echo -e "Testing with $ARG"
		echo -e "Number of operations: \c"
		./push_swap $ARG | wc -l
		if [ "$BONUS" = true ]; then
			echo -e "Checker result: \c"
			./push_swap $ARG | ./checker $ARG
		fi
		echo -e "\n"
	done
}

function selection {
	echo -e "Please enter the number of tests you would like to run:"
	echo -e "1. 3 numbers\n2. 5 numbers\n3. 100 numbers\n4. 500 numbers\n"
	echo -e "Enter your selection here: \c"
	
	read TESTS
	echo "Running no $TESTS tests..."
	
	case $TESTS in
		1)
			test 3
			;;
		2)
			test 5
			;;
		3)
			test 100
			;;
		4)
			test 500
			;;
		*)
			echo "Invalid input. Exiting..."
			exit 1
			;;
	esac
}

echo -e $RESET

if [ "$1" == "clean" ]; then
    clean
	make fclean
    echo "Cleaning complete."
    exit 0
elif [ "$1" == "bonus" ]; then
	make bonus
	BONUS=true
elif [ ! -x "./push_swap" ]; then
	make
fi

echo -e "${bold}Welcome to the push_swap tester!${normal}\n"
echo -e "This script will run a series of tests on the push_swap program."
echo -e "The program will generate a series of random numbers and pass them to push_swap.\n"
echo -e "The number of operations will be counted and displayed.\n"
echo -e "The program will continue to run tests until you stop it with ctrl+c.\n"

selection
#!/bin/bash

EXEC=./Replace
INPUT=test_input.txt
VALGRIND="valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=42"

function header() {
	echo -e "\n\e[1;32m=== $1 ===\e[0m"
}

function run_valgrind() {
	CMD="$VALGRIND $EXEC $@"
	echo -e "\e[0;36m$CMD\e[0m"
	$CMD
	if [ $? -eq 42 ]; then
		echo -e "\e[1;31mValgrind: Error detected\e[0m"
	else
		echo -e "\e[1;32mValgrind: OK\e[0m"
	fi
}

# Clean
rm -f $INPUT $INPUT.replace

# Test 1: Replace 'banana' with 'apple'
header "Test 1: Replace 'banana' with 'apple'"
echo -e "banana is good.\nI like banana!" > $INPUT
run_valgrind $INPUT banana apple
cat $INPUT.replace

# Test 2: s1 not in file
header "Test 2: Replace 'orange' (not in file) with 'kiwi'"
run_valgrind $INPUT orange kiwi
cat $INPUT.replace

# Test 3: s1 == s2
header "Test 3: Replace 'apple' with 'apple' (should copy only)"
run_valgrind $INPUT apple apple
cat $INPUT.replace

# Test 4: s1 empty (should print error, not run valgrind)
header "Test 4: Empty s1"
echo -e "\e[0;36m$EXEC $INPUT \"\" kiwi\e[0m"
$EXEC $INPUT "" kiwi

# Test 5: input file not exist
header "Test 5: Non-existent in

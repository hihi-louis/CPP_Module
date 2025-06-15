#!/bin/bash
make re

printf "ADD\nJohn\nDoe\nJohnny\n1234567890\nSecret 1\n" > input.txt
printf "ADD\nJane\nSmith\nJaney\n0987654321\nSecret 2\n" >> input.txt
printf "ADD\nAlice\nJohnson\nAli\n3333333333\nSecret 3\n" >> input.txt
printf "ADD\nBob\nBrown\nBobby\n4444444444\nSecret 4\n" >> input.txt
printf "ADD\nCharlie\nWhite\nChuck\n5555555555\nSecret 5\n" >> input.txt
printf "ADD\nDiana\nBlack\nDi\n6666666666\nSecret 6\n" >> input.txt
printf "ADD\nEve\nGreen\nEvie\n7777777777\nSecret 7\n" >> input.txt
printf "ADD\nFrank\nBlue\nFranky\n8888888888\nSecret 8\n" >> input.txt
printf "ADD\nGrace\nRed\nGracey\n9999999999\nSecret 9\n" >> input.txt
printf "ADD\nHank\nYellow\nHanky\n0000000000\nSecret 10\n" >> input.txt

# Thực hiện tìm kiếm
printf "SEARCH\n0\nEXIT\n" >> input.txt

# Chạy chương trình
valgrind ./phonebook < input.txt

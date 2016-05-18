#
#	@file	: makefile
#	@author	: Gehrig Keane
#	@date	: 2015.9.14
#	Purpose	: makefile
#

OBJS = main.o
HPPS = Hash.h Hash.hpp
CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -c $(DEBUG)
LFLAGS = -std=c++11 -Wall $(DEBUG)

lab3: $(OBJS)
	$(CC) $(LFLAGS) main.o -o lab3

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	@echo "Cleaning: "
	rm *.o lab3 

run: clean lab3
	@echo "Executing: "
	./lab3 < inpt

tar:
	@echo "Tar'ing: "
	tar -cvzf Keane_lab3.tar.gz main.cpp makefile data.txt \
	$(HPPS)

val: clean lab3
	valgrind --leak-check=full --show-leak-kinds=all ./lab3

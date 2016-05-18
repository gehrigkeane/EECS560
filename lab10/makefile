#
#	@file	: makefile
#	@author	: Gehrig Keane
#	@date	: 2015.11.17
#	Purpose	: makefile
#

OBJS = main.o
Binomial = Binomial.h Binomial.hpp List.h Node.h

CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -c $(DEBUG)
LFLAGS = -std=c++11 -Wall $(DEBUG)


all: clean run

lab10: $(OBJS)
	$(CC) $(LFLAGS) main.o -o lab10

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp

run: lab10
	./lab10

val: clean lab10
	valgrind --leak-check=full --show-leak-kinds=all ./lab10

clean:
	@echo "Cleaning: "
	rm -f *.o lab10

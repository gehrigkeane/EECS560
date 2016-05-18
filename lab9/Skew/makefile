#
#	@file	: makefile
#	@author	: Gehrig Keane
#	@date	: 2015.9.14
#	Purpose	: makefile
#

OBJS = main.o

LEFT = skew.h Skew.hpp List.h Hnode.h

CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -c $(DEBUG)
LFLAGS = -std=c++11 -Wall $(DEBUG)

all: clean run

lab9: $(OBJS)
	$(CC) $(LFLAGS) main.o -o skew

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp

run: lab9
	./skew

clean:
	@echo "Cleaning: "
	rm -f *.o skew
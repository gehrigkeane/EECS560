#
#	@file	: makefile
#	@author	: Gehrig Keane
#	@date	: 2015.11.09
#	Purpose	: makefile
#

OBJS = main.o

LEFT = leftist.h List.h Hnode.h

CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -c $(DEBUG)
LFLAGS = -std=c++11 -Wall $(DEBUG)

all: clean run

lab9: $(OBJS)
	$(CC) $(LFLAGS) main.o -o leftist

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp

run: lab9
	./leftist

clean:
	@echo "Cleaning: "
	rm -f *.o leftist
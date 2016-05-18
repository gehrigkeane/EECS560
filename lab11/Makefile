#
#	@file	: makefile
#	@author	: Gehrig Keane
#	@date	: 2015.11.17
#	Purpose	: makefile
#

OBJS = main.o
Set = MST.h Set.h sNode.h eNode.h
Other = MST.hpp Set.hpp

CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -c $(DEBUG)
LFLAGS = -std=c++11 -Wall $(DEBUG)

all: clean run

lab11: $(OBJS)
	$(CC) $(LFLAGS) main.o -o lab11

main.o: main.cpp $(Set)
	$(CC) $(CFLAGS) main.cpp -c -g

tar:
	@echo "Tar'ing: "
	tar -cvzf Keane_lab11.tar.gz main.cpp makefile data.txt \
	$(Set) $(Other)

run: lab11
	./lab11

clean:
	@echo "Cleaning: "
	rm -f *.o lab11

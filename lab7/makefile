#
#	@file	: makefile
#	@author	: Gehrig Keane
#	@date	: 2015.10.19
#	Purpose	: makefile
#

OBJS = main.o
HPPS = Heap.h Heap.hpp
CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -c $(DEBUG)
LFLAGS = -std=c++11 -Wall $(DEBUG)

lab7: $(OBJS) $(OBJS)
	$(CC) $(LFLAGS) main.o -o lab7

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	@echo "Cleaning: "
	rm *.o lab7

tar:
	@echo "Tar'ing: "
	tar -cvzf Keane_lab7.tar.gz main.cpp \
	makefile data.txt $(HPPS)

val: clean lab7
	valgrind --leak-check=full --show-leak-kinds=all ./lab7
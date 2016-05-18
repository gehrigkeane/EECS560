#
#	@file	: makefile
#	@author	: Gehrig Keane
#	@date	: 2015.9.14
#	Purpose	: makefile
#

OBJS = main.o
C_OBJS = Cmain.o
O_OBJS = Omain.o
C_HPPS = OHash.h OHash.hpp CNode.h
O_HPPS = OHash.h OHash.hpp List.h List.hpp Core.h ONode.h
CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -c $(DEBUG)
LFLAGS = -std=c++11 -Wall $(DEBUG)

lab6: $(OBJS) $(C_OBJS) $(O_OBJS)
	$(CC) $(LFLAGS) main.o -o lab6
	$(CC) $(LFLAGS) Cmain.o -o closed
	$(CC) $(LFLAGS) Omain.o -o open

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Cmain.o: Cmain.cpp
	$(CC) $(CFLAGS) Cmain.cpp

Omain.o: Omain.cpp
	$(CC) $(CFLAGS) Omain.cpp

clean:
	@echo "Cleaning: "
	rm *.o closed open lab6

tar:
	@echo "Tar'ing: "
	tar -cvzf Keane_lab6.tar.gz Cmain.cpp Omain.cpp main.cpp Timer.cpp  \
	makefile data.txt Keane_Lab06.pdf $(C_HPPS) $(O_HPPS)

val: clean lab6
	valgrind --leak-check=full --show-leak-kinds=all ./lab6
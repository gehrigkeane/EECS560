#
#	@file	: makefile
#	@author	: Gehrig Keane
#	@date	: 2015.9.14
#	Purpose	: makefile
#

OBJS = main.o
HPPS = BinarySearchTree.h BinarySearchTree.hpp Container.h Leaf.h Queue.h
CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -c -w $(DEBUG)
LFLAGS = -std=c++11 -Wall $(DEBUG)

lab5: $(OBJS)
	$(CC) $(LFLAGS) main.o -o lab5

main.o: main.cpp BinarySearchTree.h Leaf.h
	$(CC) $(CFLAGS) main.cpp

clean:
	@echo "Cleaning: "
	rm *.o lab5 

run: lab5
	@echo "Executing: "
	./lab5 < inpt

tar:
	@echo "Tar'ing: "
	tar -cvzf Keane_lab5.tar.gz main.cpp makefile data.txt \
	$(HPPS)

#A file labeled test must exist with correctly formatted inputs
val: lab5
	valgrind --leak-check=full --show-leak-kinds=all ./lab5 < inpt

OBJS = main.o BinaryTree.o Node.o LinkedList.o
CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -c $(DEBUG)
LFLAGS = -std=c++11 -Wall $(DEBUG)

lab2: $(OBJS)
	$(CC) $(LFLAGS) main.o BinaryTree.o Node.o -o lab2

main.o: main.cpp BinaryTree.h Node.h LinkedList.h
	$(CC) $(CFLAGS) main.cpp

BinaryTree.o: BinaryTree.h BinaryTree.cpp
	$(CC) $(CFLAGS) BinaryTree.cpp

Node.o: Node.h Node.cpp
	$(CC) $(CFLAGS) Node.cpp

clean:
	rm *.o lab2 

tar:
	tar -cvzf Keane_lab2.tar.gz main.cpp makefile data.txt README.txt testInput.txt\
	Node.cpp Node.h BinaryTree.cpp BinaryTree.h LinkedList.cpp LinkedList.h

test:
	./lab2 < testInput.txt
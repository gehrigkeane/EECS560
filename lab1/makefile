OBJS = main.o LinkedList.o Node.o
CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -c $(DEBUG)
LFLAGS = -std=c++11 -Wall $(DEBUG)

lab01: $(OBJS)
	$(CC) $(LFLAGS) main.o LinkedList.o Node.o -o lab1

main.o: main.cpp LinkedList.h Node.h
	$(CC) $(CFLAGS) main.cpp

LinkedList.o: LinkedList.h LinkedList.cpp
	$(CC) $(CFLAGS) -w LinkedList.cpp

Node.o: Node.h Node.cpp
	$(CC) $(CFLAGS) Node.cpp

clean:
	rm *.o lab1 

tar:
	tar -cvzf Keane_Lab1.tar.gz main.cpp makefile data.txt README.txt testInput.txt\
	Node.cpp Node.h LinkedList.cpp LinkedList.h

test:
	./lab1 < testInput.txt
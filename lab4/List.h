/*
*	@file	: List.h
*	@author	: Gehrig Keane
*	@date	: 2015.09.21
*	Purpose	: simple list header from lab 1
*/

#ifndef List_H
#define List_H

#include <iostream> /** NULL */
#include "Node.h" /****/

class List
{
	public:
	//Constructors-Destructors
	List();
	~List();

	//Accessors
	bool isEmpty() const;
	int size() const;
	bool search(int value) const;
	void printList() const;

	//Insert Mutators
	void addBack(int value);
	void addFront(int value);

	//Remove Mutators
	bool removeBack();
	int pop();
	void push(int x);
	bool removeFront();
	bool erase(int value);
	Node* Find(int value) const;

	private:
	Node* m_front;
	int m_size;
};
#include "List.hpp"
#endif

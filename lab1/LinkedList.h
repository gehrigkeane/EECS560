/*
*	@file	: LinkedList.h
*	@author	: Gehrig Keane
*	@date	: 2015.08.24
*	Purpose	: Header file for the Linked List class
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream> /** NULL */
#include "Node.h" /****/

class LinkedList
{
	public:
	LinkedList();

	~LinkedList();

	void insert(int value);

	bool isEmpty() const;

	void print() const;

	char* erase(int val);

	Node* Find(int value) const;

	int size() const;

	private:
	Node* m_front;
	int m_size;
};

#endif
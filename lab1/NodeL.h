/*
*	@file	: Node.h
*	@author	: Gehrig Keane
*	@date	: 2015.08.24
*	Purpose	: Header file for the Node class
*/

#ifndef NODE_H
#define NODE_H

#include <iostream> /** NULL */

class Node
{
	public:

	Node();

	Node(int value, Node* next);

	void setValue(int val);

	int getValue();

	void setNext(Node* prev);

	Node* getNext();

	private:
	int m_value;	//the value in the node
	Node* m_next;	//a pointer to another node
};

#endif	
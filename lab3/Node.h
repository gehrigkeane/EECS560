/*
*	@file	: Node.h
*	@author	: Gehrig Keane
*	@date	: 2015.9.14
*	Purpose	: Header file for the Node class
*/

#ifndef NODE_H
#define NODE_H

#include <iostream> /** NULL */

class Node
{
	public:
	//Constructors-Destructors
	Node();
	Node(int value, Node* next);

	void scrub();

	//Accessors
	void setValue(int val);
	void setFlag(bool val);
	void setNext(Node* prev);

	//Mutators
	int getValue();
	bool getFlag();
	Node* getNext();

	private:
	int m_value;	//the value in the node
	bool flag;		//rewritten flag
	Node* m_next;	//a pointer to another node
};
#include "Node.hpp"
#endif

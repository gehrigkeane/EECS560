/*
*	@file	: Node.h
*	@author	: Gehrig Keane
*	@date	: 2015.9.21
*	Purpose	: Header file for the Node class
*/

#ifndef NODE_H
#define NODE_H

#include <iostream> /** NULL */

class Node
{
	private:
	int m_value;	//the value in the node
	Node* m_next;	//a pointer to another node
	
	public:
	//Constructors-Destructors
	Node() { m_next = nullptr; }
	Node(int value) { m_value = value; m_next = nullptr; }
	Node(int value, Node* next) { m_value = value; m_next = next; }

	//Accessors
	void setValue(int val) { m_value = val; }
	void setNext(Node* next) { m_next = next; }

	//Mutators
	int getValue() { return m_value; }
	Node* getNext() { return m_next; }
};
//#include "Node.hpp"
#endif

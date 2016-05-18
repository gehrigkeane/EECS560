/*
*	@file	: Node.cpp
*	@author	: Gehrig Keane
*	@date	: 2015.08.24
*	Purpose	: Node class implementation
*/

#include "Node.h"

Node::Node()
{
	m_value = 0;
	m_next = nullptr;
}//Node Default Constructor

Node::Node(int value, Node* next)
{
	m_value = value;
	m_next = next;
}//Node value constructor

void Node::setValue(int val)
{
	m_value = val;
}//setValue - set node value to that of the argument

int Node::getValue()
{
	return m_value;
}//getValue - returns the nodes value

void Node::setNext(Node* next)
{
	m_next = next;
}//setNext - sets m_next to the argument Node

Node* Node::getNext()
{
	return m_next;
}//getNext - returns m_next
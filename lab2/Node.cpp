/*
*	@file	: Node.h
*	@author	: Gehrig Keane
*	@date	: 2015.08.31
*	Purpose	: Provides the functionality for the Node class
*/

#include "Node.h"

Node::Node()
{
	m_value = 0;
	m_left = nullptr;
	m_right = nullptr;
}//Node Default Constructor


Node::Node(int value, Node* next)
{
	m_value = value;
	m_next = next;
}//Node value constructor


int Node::getValue()
{
	return m_value;
}//getValue - accessor

Node* Node::getLeft()
{
	return m_left;
}//getLeft - accessor

Node* Node::getRight()
{
	return m_right;
}//getRight - accessor

void Node::setValue(int value)
{
	m_value = value;
}//setValue - mutator

void Node::setLeft(Node* left)
{
	m_left = left;
}//setLeft - mutator

void Node::setRight(Node* right)
{
	m_right = right;
}//setRight - mutator
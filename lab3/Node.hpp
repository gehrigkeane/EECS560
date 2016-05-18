/*
*	@file	: Node.hpp
*	@author	: Gehrig Keane
*	@date	: 2015.9.14
*	Purpose	: Node class implementation
*/

Node::Node()
{
	m_value = -1;
	flag = false;
	m_next = nullptr;
}//Node Default Constructor

Node::Node(int value, Node* next)
{
	m_value = value;
	flag = false;
	m_next = next;
}//Node value constructor

void Node::setValue(int val)
{
	m_value = val;
}//setValue - set node value to that of the argument

void Node::setFlag(bool val)
{
	flag = val;
}//setFlag

void Node::setNext(Node* next)
{
	m_next = next;
}//setNext - sets m_next to the argument Node

int Node::getValue()
{
	return m_value;
}//getValue - returns the nodes value

bool Node::getFlag()
{
	return flag;
}//getFlag

Node* Node::getNext()
{
	return m_next;
}//getNext - returns m_next

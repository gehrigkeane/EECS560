/*
*	@file	: Node.h
*	@author	: Gehrig Keane
*	@date	: 2015.9.21
*	Purpose	: Header file for the Node class
*/

#ifndef ONODE_H
#define ONODE_H

#include <iostream> /** NULL */

class ONode
{
	private:
	long m_value;	//the value in the ONode
	ONode* m_next;	//a pointer to another ONode
	
	public:
	//Constructors-Destructors
	ONode()							{ m_next = nullptr; }
	ONode(long value)				{ m_value = value; m_next = nullptr; }
	ONode(long value, ONode* next)	{ m_value = value; m_next = next; }

	//Accessors
	void setValue(long val)		{ m_value = val; }
	void setNext(ONode* next)	{ m_next = next; }

	//Mutators
	long getValue()		{ return m_value; }
	ONode* getNext()	{ return m_next; }
};
//#include "ONode.hpp"
#endif

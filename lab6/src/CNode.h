/*
*	@file	: CNode.h
*	@author	: Gehrig Keane
*	@date	: 2015.9.14
*	Purpose	: CNode class implementation
*/

#ifndef CNODE_H
#define CNODE_H

#include <iostream> /** NULL */

class CNode
{
	public:
	//Constructors-Destructors
	CNode()							{ m_value = -1; flag = false; m_next = nullptr; }
	CNode(long value, CNode* next)	{ m_value = value; flag = false; m_next = next; }

	//void scrub() {  }

	//Accessors
	void setValue(long val)		{ m_value = val; }
	void setFlag(bool val)		{ flag = val; }
	void setNext(CNode* next)	{ m_next = next; }

	//Mutators
	long getValue()		{ return m_value; }
	bool getFlag()		{ return flag; }
	CNode* getNext()	{ return m_next; }

	private:
	long m_value;	//the value in the CNode
	bool flag;		//rewritten flag
	CNode* m_next;	//a pointer to another CNode
};
#endif

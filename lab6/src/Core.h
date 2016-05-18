/*
*	@file	: Core.h
*	@author	: Gehrig Keane
*	@date	: 2015.9.21
*	Purpose	: Header file for the Core class
*/

#ifndef CORE_H
#define CORE_H

#include <iostream> /** NULL */
#include "List.h"

class Core
{
	private:
	List* m_list;
	Core* m_next;	//a pointer to another Core
	
	public:
	//Constructors-Destructors
	Core() { m_list = nullptr; m_next = nullptr; }
	Core(Core* next) { m_list = nullptr; m_next = next; }

	//Accessors
	void setList(List* list) { m_list = list; }
	void setNext(Core* next) { m_next = next; }

	//Mutators
	List* getList() { return m_list; }
	Core* getNext() { return m_next; }
};
#endif

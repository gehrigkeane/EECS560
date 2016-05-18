/*
*	@file	: Container.h
*	@author	: Gehrig Keane
*	@date	: 2015.9.28
*	Purpose	: Implementation of the Container class
*/

#ifndef CONTAINER_H
#define CONTAINER_H

#include "Leaf.h"

class Container {
	public:
		//Constructors-Destructors
		Container();
		Container(Leaf* val) 						{ value = val; next = nullptr; }
		Container(Leaf* val, Container* newCont)	{ value = val; next = newCont; }

		//Accessors
		void setNext(Container* newCont)			{ next = newCont; }
		
		//Mutators
		Container* getNext()						const { return next; }
		Leaf* getValue()							const { return value; }
	
	private:
		Leaf* value;
		Container* next;
};

#endif

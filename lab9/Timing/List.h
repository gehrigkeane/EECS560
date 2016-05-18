/*
*	@file	: List.h
*	@author	: Gehrig Keane
*	@date	: 2015.11.09
*	Purpose	: List header + implementation file
*/

#ifndef LIST_H
#define LIST_H

#include "Hnode.h"
#include <iostream>

class List{
	public:
		List()				{ for(int i = 0; i < size; i++) { list[i] = nullptr; } }
		~List()				{ for(int i = 0; i < size; i++) { list[i] = nullptr; } }
		bool isEmpty()		{ if(active != 0) { return false; } return true; }
		Hnode* peek()		{ return list[0]; }
		
		void push(Hnode* node)
		{
			if(active == size)
			{
				size = 2*size;
				Hnode** temp = new Hnode*[size];
				for(int i = 0; i <= active; i++)
					temp[i] = list[i];
				list = temp;
			}//resize array on growth
			list[active] = node;
			active++;
		}//push

		Hnode* pop()
		{
			Hnode* temp = list[0];
			for(int i = 0; i <= active; i++)
				list[i] = list[i+1];
			active--;
			return temp;
		}//pop - 

	private:
		int size = 4;
		int active = 0;
		Hnode** list = new Hnode*[size];
};
#endif

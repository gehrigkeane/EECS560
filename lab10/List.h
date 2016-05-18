/*
*	@file	: List.h
*	@author	: Gehrig Keane
*	@date	: 2015.11.17
*	Purpose	: provide list functionality
*/

#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List{
	public:
		List()				{}
		~List()				{ delete[] list; }
		Node* peek()		{ return list[0]; }
		bool isEmpty()		{ if ( count == 0 ) { return true; } return false; }
		Node* pop()
		{
			Node* temp = list[0];
			for(int i = 0; i < size-1; i++) { list[i] = list[i+1]; }
			count--;
			return temp;
		}//pop - remove first list element

		void push(Node* n)
		{
			if(count == size-1)
			{
				Node** temp = new Node*[size*2];
				for(int i = 0; i < size; i++) { temp[i] = list[i]; }
				list = temp;
				size = size*2;
			}
			list[count] = n;
			count++;
		}//push - insert new element

	private:
		int size = 100;
		int count = 0;
		Node** list = new Node*[size];
};
#endif

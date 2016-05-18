/*
*	@file	: Binomial.h
*	@author	: Gehrig Keane
*	@date	: 2015.11.17
*	Purpose	: provide Binomial Queue functionality
*/

#ifndef BINOMIAL_H
#define BINOMIAL_H

#include <fstream>		//File I/O
#include <iostream>		//Standard I/O
#include <sstream>		//File Line Stream - See Build
#include <string>		//File Line Stream - See Build

#include "Node.h"
#include "List.h"

#define size 100

class Binomial {
	public:
		Binomial()				{ for(int i = 0; i<size; i++) { queue[i] = nullptr; } }
		void insert(int x)		{ Node* t = new Node(x); Merge(t); }
		void build();
		void Merge(Node* a);
		void deleteMin();
		void levelorder();
		
		~Binomial()
		{
			delete child; delete right; 
			for(int i = 0; i<size; i++)
			{
				Node* temp = queue[i];
				queue[i] = nullptr;
				delete temp;
			}//for - each element delete Node
		}//destructor

	private:
		List* child = new List();
		List* right = new List();
		Node* queue[size];
};
#include "Binomial.hpp"
#endif

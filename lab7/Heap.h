/*
*	@file	: Heap.h
*	@author	: Gehrig Keane
*	@date	: 2015.10.19
*	Purpose	: Heap header file
*/

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <stdlib.h>
#include <limits.h>

class Heap {

	public:
	//Constructors-Destructors
	Heap() { for ( int i = 0; i < 500; i++ ) { heap_arr[i] = INT_MAX; } }

	//Lab Required Fucntions - Public
	void insert(int x);
	void remove(int x);
	void deleteMin() 	{ remove(heap_arr[0]); }
	void deleteMax() 	{ remove(max); }
	void levelorder();
	
	//Helper Functions
	void bottomUp();

	private:
	//Lab Required functions - Private
	void insert(int x, int index, int parent);

	//Helper Functions
	bool isEmpty() 		{ if ( active == 0 ) { return true; } return false; }
	void isMax(int val)	{ if ( max < val ) { max = val; } }
	void reHeap(int i);
	int minChildPosition(int position);

	int heap_arr[500];
	int max = 0;
	int active = 0;
};
#include "Heap.hpp"
#endif

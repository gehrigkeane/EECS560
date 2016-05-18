/*
*	@file	: MinMaxHeap.h
*	@author	: Gehrig Keane
*	@date	: 2015.10.26
*	Purpose	: MinMaxHeap header file
*/

#ifndef MINMAXHEAP_H
#define MINMAXHEAP_H

#include <iostream>
#include <stdlib.h>
#include <limits.h>

class MinMaxHeap {

	public:
	//Constructors-Destructors
	MinMaxHeap() { for ( int i = 0; i < 500; i++ ) { heap_arr[i] = INT_MAX; } }

	//Lab Required Fucntions - Public
	void insert(int x);
	void remove(int x);
	void deleteMin() 	{ remove(heap_arr[0]); }
	void deleteMax() 	{ remove(std::max(heap_arr[1], heap_arr[2])); }
	void levelorder();
	
	//Helper Functions
	void bottomUp();

	private:
	//Lab Required functions - Private
	void insert(int x, int index, int parent);

	//Helper Functions
	bool isEmpty() 		{ return active == 0 ? true: false; }
	void isMax(int val)	{ max = ( max < val ) ? val : max; }
	void reHeap(int i);
	bool minLevel(int location);
	int minChildPosition(int position);
	int min_adjust(int index1, int index2);
	int max_adjust(int index1, int index2);

	int heap_arr[500];
	int max = 0;
	int active = 0;
};
#include "MinMaxHeap.hpp"
#endif

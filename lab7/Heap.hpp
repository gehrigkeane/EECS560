/*
*	@file	: Heap.hpp
*	@author	: Gehrig Keane
*	@date	: 2015.10.19
*	Purpose	: Heap functionality implementation
*/

#include <string>
#include <fstream>
#include <sstream>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		Lab Required Functions
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Heap::insert(int value)
{
	int parent = (active-1)/5;
	isMax(value);
	insert(value, active, parent);
	active++;
}//insert

void Heap::insert(int value, int index, int parent)
{
	if ( parent == 0 )
	{
		if ( value < heap_arr[parent] )
		{
			heap_arr[index] = heap_arr[parent];
			heap_arr[parent] = value;
		}//if - value is less than parent, swap
		else	//else - place value
			heap_arr[index] = value;
	}//if - base case for 1:5
	else if ( value < heap_arr[parent] )
	{
		heap_arr[index] = heap_arr[parent];
		insert(value, parent, (parent-1)/5);
	}//else if - value is less than parent, swap
	else	//else - place value
		heap_arr[index] = value;
}//insert - recursive definition

void Heap::remove(int value)
{
	for ( int i = 0; i < active; i++ )
	{
		if ( heap_arr[i] == value )
		{
			if ( i != active - 1 )
			{
				heap_arr[i] = heap_arr[active - 1];
				heap_arr[active-1] = INT_MAX;
				for ( int i = active; i >= 0; i-- )
				{
					reHeap(i);
				}//for - bottomup reHeap
			}//if - replace with last value, reHeap
			else
			{
				heap_arr[active-1] = INT_MAX;
			}//else - value is last in heap, simple case
			active--;
			remove(value);
			break;
		}//if - remove found value
	}//for - traverse heap linearly
}//remove

void Heap::levelorder()
{
	int nline = 5;
	std::cout << std::endl <<  heap_arr[0];
	std::cout << std::endl;
	for(int i = 1; i < active; i++)
	{
		std::cout << heap_arr[i] << " ";
		if (i%5 == 0)
		{
			if (i != nline)
			{
				std::cout << " - ";
			}//if - delineate groups of children
			else
			{
				std::cout << std::endl;
				nline += nline*nline; // move new line counter to n^2+n
			}//else - append new line counter
		}//if - next set of 5 reached
	}//for - traverse heap linearly
	std::cout << "\n";
}//levelorder

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		Helper Functions
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Heap::bottomUp()
{
	std::ifstream fp;
	fp.open("data.txt");
	if ( !fp )
		std::cout << "\nFailed to open 'data.txt', please ensure file exists!" << std::endl;
	else
	{
		std::string line;

		while ( std::getline(fp, line) )
		{
			std::stringstream  lineStream(line);
			int value;
			while ( lineStream >> value )
			{
				isMax(value);
				heap_arr[active] = value;
				active++;
			}//while - strings in the stream
		}//while - lines in the file
		fp.close();

		for ( int i = active; i >= 0; i-- )
		{
			reHeap(i);
		}//for - bottomup reHeap
	}//else - file opened correctly
}//bottomUp

int Heap::minChildPosition(int position)
{
	int min = 5*position+1;
	for ( int i = 2; i <= 5; i++ )
	{
		if ( heap_arr[5*position+i] < heap_arr[min] )
			min = 5*position+i;
	}//for - locate minimum child
	return min;
}//minChildPosition - locate minimum child

void Heap::reHeap(int position)
{
	int min = minChildPosition(position);
	if ( heap_arr[min] < heap_arr[position] )
	{
		int tmp = heap_arr[min];
		heap_arr[min] = heap_arr[position];
		heap_arr[position] = tmp;
		reHeap(min);
		reHeap(position);
	}//if - min child < parent recurse
}//reHeap - sub-heap

/*
*	@file	: Heap.hpp
*	@author	: Gehrig Keane
*	@date	: 2015.10.26
*	Purpose	: Heap functionality implementation
*/

#include <string>
#include <fstream>
#include <sstream>
#include <math.h>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		Lab Required Functions
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void MinMaxHeap::insert(int value)
{
	active++;
	heap_arr[active-1] = value;
	for ( int i = (active-1)/2; i >= 0; i-- )
	{
		reHeap(i);
	}//for - 
}//insert

void MinMaxHeap::remove(int value)
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

void MinMaxHeap::levelorder()
{
	if ( active == 0 )
	{
		std::cout << "\nEmpty Heap" << std::endl;
	}//if - empty heap
	else
	{	
		int nline = 1;
		int count = 1;
		std::cout << heap_arr[0];
		for ( int i = 2; i <= active; i++ )
		{
			if( count != nline )
			{
				count++;
				std::cout << heap_arr[i-1] << " ";
			}//if - 
			else
			{
				count = 1;
				nline = nline*2;
				std::cout << std::endl << heap_arr[i-1] << " ";
			}//else - reset count, iterate nline
		}//for - traverse heap linearly
	}//else - continue
}//levelorder

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		Helper Functions
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void MinMaxHeap::bottomUp()
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
		{ reHeap(i); }//for - bottomup reHeap
	}//else - file opened correctly
}//bottomUp


void MinMaxHeap::reHeap(int position)
{
	int min = minChildPosition(position);
	if ( 2*position+1 >= active )
		return;

	if ( minLevel(position) )
	{
		if ( heap_arr[min] < heap_arr[position] )
		{
			int tmp = heap_arr[position];
			heap_arr[position] = heap_arr[min];
			heap_arr[min] = tmp;
			reHeap(position);
			reHeap((min-1)/2);
			reHeap(min);
		}//if - less than minarat
	}//if - heapify min level
	else
	{
		if ( heap_arr[min] > heap_arr[position] )
		{
			int tmp = heap_arr[position];
			heap_arr[position] = heap_arr[min];
			heap_arr[min] = tmp;
			reHeap(position);
			reHeap((min-1)/2);
			reHeap(min);
		}//if - greater than comparator
	}//else - heapify max level
}//reHeap - sub-heap

int MinMaxHeap::minChildPosition(int position)
{
	int min = 2*position+1; // fill in with a default value
	if ( 2*position+1 >= active )
		return 2*position+1;

	for ( int i = 1; i <= 2; i++ )
	{
		if ( minLevel(position) )
		{
			min = min_adjust(2*position+i, min);
			for( int x = 1; x <= 2; x++ )
			{ min = min_adjust(2*(2*position+i)+x, min); }//for - 
		}//if - minlevel
		else
		{
			min = max_adjust(2*position+1, min);
			for( int x = 1; x <= 2; x++ )
			{ min = max_adjust(2*(2*position+i)+x, min); }//for - 
		}//else - maxlevel
	}//for - immediate adjustments
	return min;
}//minChidPosition

bool MinMaxHeap::minLevel(int location)
{
	return int(trunc(log2(location+1)))%2==0;
}//isMinLevel

int MinMaxHeap::min_adjust(int i1, int i2)
{
	if ( heap_arr[i1] < heap_arr[i2] )
	{ if (i1 < active) { return i1; } }//if - 
	return i2;
}//min_adjust

int MinMaxHeap::max_adjust(int i1, int i2)
{
	if ( heap_arr[i1] > heap_arr[i2] )
	{ if (i1 < active) { return i1; } }//if - 
	return i2;
}//max_adjust

#ifndef MINMAXHEAP_H
#define MINMAXHEAP_H
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <limits.h>

class MinMaxHeap {

	private:
		int heap_arr[500];
		int active = 0;
		bool search(int x);
		bool insert_helper(int x, int parent, int cur_loc);
		void reHeap(int i);
		bool isminlevel(int location);
		
	public:
		MinMaxHeap();
		minmaxheap(std::string input_file);
		bool is_empty();
		void insert(int x);
		void remove(int x);
		void delete_min();
		void delete_max();
		void level_order();
};
#include "MinMaxHeap.hpp"
#endif
/*
*   @file   : Set.h
*   @author : Gehrig Keane
*   @date   : 2015.12.02
*   Purpose : Disjoint Set header file
*/

#ifndef _DIS_SET
#define _DIS_SET
#include "sNode.h"

class Set {
	public:
		Set();
		Set(int size);
		~Set() { delete[] node_arr; }

		void Union(int seti, int setj);
		int find(int value);

	private:
		int size;
		sNode** node_arr;
		sNode* find(sNode* setPtr);
};

#include "Set.hpp"
#endif

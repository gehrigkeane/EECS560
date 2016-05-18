/*
*	@file	: Hnode.h
*	@author	: Gehrig Keane
*	@date	: 2015.11.09
*	Purpose	: Hnode header + implementation file
*/

#ifndef NODE_H
#define NODE_H

#include <algorithm>
#include <limits.h>

class Hnode {
	public:
		Hnode()						{ right = nullptr; left = nullptr; value = INT_MAX; }
		Hnode(int val)				{ left = nullptr; right = nullptr; value = val; setRank(); }
		~Hnode()					{ if (left != nullptr) { delete left; }
									  if (right != nullptr) { delete right; } }
		
		void setLeft(Hnode* node)	{ left = node; setRank(); }
		void setRight(Hnode* node)	{ right = node; setRank(); }
		void setValue(int val)		{ value = val; }

		Hnode* getLeft()			{ return left; }
		Hnode* getRight()			{ return right; }
		int getValue()				{ return value; }
		int getRank()				{ return rank; }
		
		void swap()					{ Hnode* temp = right; right = left; left = temp; }
		bool isEmpty()				{ if ( value == INT_MAX ) { return true; } return false; }
		void setRank()				{ if (left == nullptr || right == nullptr) { rank = 0; }
									  else { rank = std::min(left->getRank(), right->getRank()) + 1; } }

	private:
		Hnode* left;
		Hnode* right;
		int value;
		int rank = 0;
};

#endif
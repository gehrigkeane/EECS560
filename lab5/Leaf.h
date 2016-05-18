/*
*	@file	: Leaf.h
*	@author	: Gehrig Keane
*	@date	: 2015.9.28
*	Purpose	: implementation of the Leaf class header
*/

#ifndef LEAF_H
#define LEAF_H

class Leaf {
	public:
		//Constructors-Destructors
		Leaf()			{ leftChild = nullptr; rightChild = nullptr; }
		Leaf(int val)	{ value = val; leftChild = nullptr; rightChild = nullptr; }
		Leaf(int val, Leaf* left, Leaf* right) { value = val; leftChild = left; rightChild = right; }
		
		//Accessors
		bool isLeaf()					const { return (getLeft() == nullptr && getRight() == nullptr); }
		int getValue()					const { return value; }
		Leaf* getLeft()					const { return leftChild; }
		Leaf* getRight()				const { return rightChild; }

		//Mutators
		void setValue(int val)			{ value = val; }
		void setLeft(Leaf* left)		{ leftChild = left; }
		void setRight(Leaf* right)		{ rightChild = right; }

	private:
		int value;
		Leaf* leftChild;
		Leaf* rightChild;
};

#endif

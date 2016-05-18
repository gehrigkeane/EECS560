/*
*	@file	: BinarySearchTree.h
*	@author	: Gehrig Keane
*	@date	: 2015.9.28
*	Purpose	: header file for the Binary Search Tree class
*/

#ifndef BST_H
#define BST_H

#include "Leaf.h"
#include "Queue.h"
#include <iostream>

enum Order {PRE_ORDER, IN_ORDER, LEVEL_ORDER};

class BinarySearchTree {
	public:
		//Constructors-Destructors
		BinarySearchTree() 			{ m_root = nullptr; }
		~BinarySearchTree()			{ deleteTree(m_root); }

		//Lab Required Functions
		void deletemin();
		void deletemax();
		void insert(int value) 		{ insert(value, this->m_root); }
		void printTree(Order order);
		void remove (const int& entry);

	private:
		Leaf* m_root;
		Queue queue;

		//Private Required Functionality 
		void insert(int value, Leaf* subtree);
		void printTree(Leaf* subtree, Order order);
		Leaf* remove(Leaf* leaf_del);
		Leaf* removeLeft(Leaf* leaf_del, int& inorderSuccessor);
		Leaf* removeSimple(Leaf* subtree, const int value, bool& success);
		
		//Private Helper Functionality
		void deleteTree(Leaf* subtree);
		int findMin(Leaf* subtree);
		int findMax(Leaf* subtree);
		bool isLeaf(Leaf* subtree);
};

#include "BinarySearchTree.hpp"
#endif

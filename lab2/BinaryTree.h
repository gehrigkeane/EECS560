/*
*	@file	: BinaryTree.h
*	@author	: Gehrig Keane
*	@date	: 2015.08.31
*	Purpose	: Header file for the BinaryTree class
*/

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>

#include <iostream>	/** NULL */
#include "Node.h"	/** Node implementation **/

class BinaryTree
{
	public:
	BinaryTree();

	~BinaryTree();

	void build();

	void add(int value, Node* subtree, int level);

	int height(Node* node);

	int largest(Node* subtree, int val) const;

	int leaves(Node* node) const;
	
	void print(Node* subtree) const;

	void deleteTree(Node* subtree);

	private:
	Node* m_root;
};

#endif
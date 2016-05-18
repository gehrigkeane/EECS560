/*
*	@file	: Skew.h
*	@author	: Gehrig Keane
*	@date	: 2015.11.09
*	Purpose	: skew heap implementation file
*/

#ifndef SKEW_H
#define SKEW_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "Hnode.h"
#include "List.h"

enum Order {PRE_ORDER, IN_ORDER, LEVEL_ORDER};

class Skew {
	public:
		Skew()	{ m_root = nullptr; }
		~Skew()	{ delete m_root; }
		void build();
		void print(Order order);
		void insert(int val);
		void deleteMin() { if ( m_root == nullptr ) { return; }
						   m_root = concat(m_root->getRight(), m_root->getLeft()); }

	private:
		Hnode* concat(Hnode* a, Hnode* b);
		void preorder(Hnode* t);
		void inorder(Hnode* t);
		void levelorder();

		int rank;
		Hnode* m_root;
};
#include "Skew.hpp"
#endif
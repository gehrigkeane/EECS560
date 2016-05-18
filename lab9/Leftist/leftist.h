/*
*	@file	: Leftist.h
*	@author	: Gehrig Keane
*	@date	: 2015.11.09
*	Purpose	: Leftist header file
*/

#ifndef LEFTIST_H
#define LEFTIST_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "Hnode.h"
#include "List.h"

enum Order {PRE_ORDER, IN_ORDER, LEVEL_ORDER};

class Leftist {
	public:
		Leftist()	{ m_root = nullptr; }
		~Leftist()	{ delete m_root; }
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
#include "leftist.hpp"
#endif

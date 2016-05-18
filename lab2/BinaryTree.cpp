/*
*	@file	: BinaryTree.cpp
*	@author	: Gehrig Keane
*	@date	: 2015.08.31
*	Purpose	: provides functionality for the BinaryTree class
*/

#include "BinaryTree.h"
#include <string.h>

BinaryTree::BinaryTree()
{
	m_root = nullptr;
}//Default Constructor

BinaryTree::~BinaryTree()
{
	if ( m_root == nullptr )
	{
		delete m_root;
	}//if - tree was never created
	else
		deleteTree(m_root);
}//Default Destructor

void BinaryTree::build()
{
	char line[1024];
	char* tok;
	int level = 0;
	FILE* fp = fopen ("data.txt","r");;


	while (fgets(line, sizeof line, fp) != NULL)
	{
		tok = strtok (line," ,.-");
		while (tok != nullptr)
		{
			//~~~~~~~~~~Add to tree HERE~~~~~~~~~~
			// add input validation
			// add((int)tok, m_root, level);

			std::cout << "Num: " << tok << std::endl;
			tok = strtok (NULL, " ,.-");
			level++;
		}
	}
}//build - build binary tree from data.txt

void BinarySearchTree::add(int value, Node* subtree, int level)
{
	/*
	if(subtree == nullptr)
	{
		subtree = new Node();
		subtree->setValue(value);
		m_root = subtree;
	}
	else if ( subtree->getLeft() == nullptr && subtree->getRight() == nullptr )
	{
		Node* temp = new Node();
		temp->setValue(value);
		subtree->setLeft(temp);
	}
	else if ( subtree->getLeft() != nullptr && subtree->getRight() == nullptr )
	{
		Node* temp = new Node();
		temp->setValue(value);
		subtree->setRight(temp);
	}
	else if(value < subtree->getValue())
	{
		if(subtree->getLeft() != nullptr)
		{
			add(value, subtree->getLeft());
		}
		else
		{
			Node* temp = new Node();
			temp->setValue(value);
			subtree->setLeft(temp);
		}
	}
	*/
}

int BinaryTree::height(Node* node)
{
    if( node == nullptr )
        return -1;

    int l = findHeight(node->getLeft());
    int r = findHeight(node->getRight());

    if( l > r )
        return l + 1;
    else
        return r + 1;
}

int BinaryTree::largest(Node* subtree, int val) const
{
	if( subtree == nullptr )
	{
		return val;
	}
	largest(subtree->getLeft(), val);
	if ( subtree->getValue() > val )
		val = subtree->getValue();
	largest(subtree->getRight(), val);
}//largest - find the largest element in the binary tree

int BinaryTree::leaves(Node* node) const
{
	if( node == nullptr )
		return 0;
	if ( node->getLeft() == nullptr && node->getRight() == nullptr )
		return 1;
	else if ( node->getLeft() == NULL && node->getRight() == nullptr )
		return leaves(node->getRight());
	else if ( node->getLeft() == nullptr && node->getRight() == NULL )
		return leaves(node->getLeft());
	else if ( node->getLeft() == NULL && node->getRight() == nullptr )
		return 1;
	else
		return leaves(node->left) + leaves(node->getRight());
}//leaves - find the number of leaves in the binary tree

void BinaryTree::print(Node* subtree) const
{
	if( subtree == nullptr )
	{
		return;
	}
	print(subtree->getLeft());
	std::cout << subtree->getValue() << " ";
	print(subtree->getRight());
}//print - prints space deliniated inline tree traversal 

void BinaryTree::deleteTree(Node* subtree)
{
	//if on a leaf then delete it and set it equal to nullptr
	if( subtree->getLeft() != nullptr )
	{
		deleteTree(subtree->getLeft());
	}//if - left node exists
	if( subtree->getRight() != nullptr )
	{
		deleteTree(subtree->getRight());
	}//if - right node exists
	delete subtree;
}//deleteTree - used to improve destructor aesthetic
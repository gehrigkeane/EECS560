/**
*	@file:		BinarySearchTree.h
*	@author:	Gehrig Keane
*	@date:		3/30/2015
*	Purpose:	The header file for the BST class
*/


#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "Node.h"

enum Order {PRE_ORDER, IN_ORDER, POST_ORDER};

template <typename T>
class BinarySearchTree
{
public:
	/**
	*  @pre none
	*  @post An initialized BST
	*  @return none
	*/
	BinarySearchTree();

	/**
	*  @pre An initialized BST
	*  @post A copy BST
	*  @return none
	*/
	BinarySearchTree(const BinarySearchTree<T>& other);

	/**
	*  @pre An initialized BST
	*  @post none
	*  @return none
	*/
	~BinarySearchTree();

	/**
	*  @pre A value to be added
	*  @post The value is added to BST
	*  @return none
	*/
	void add(T value);

	/**
	*  @pre An order
	*  @post Prints the tree in the given order
	*  @return none
	*/
	void printTree(Order order);

	Node<T>* search(T value);


private:
	/**
	*  @pre A value and a subtree
	*  @post The value is added to the BST
	*  @return none
	*/
	void add(T value, Node<T>* subtree);

	/**
	*  @pre A BST to be deleted
	*  @post recursively deletes the BST
	*  @return none
	*/
	void deleteTree(Node<T>* subtree);

	/**
	*  @pre A value and a subtree
	*  @post none
	*  @return A pointer based on whether the value is in the tree or not
	*/
	Node<T>* search(T value, Node<T>* subtree);

	/**
	*  @pre an order and a subtree
	*  @post Prints the BST based on the order given
	*  @return none
	*/
	void printTree(Node<T>* subtree, Order order) const;

	Node<T>* m_root;

};

#include "BinarySearchTree.hpp"

#endif // BINARYSEARCHTREE_H













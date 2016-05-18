/**
*	@file:		BinarySearchTree.hpp
*	@author:	Gehrig Keane
*	@date:		3/30/2015
*	Purpose:	Provides the functionality for the BST class
*/

#include <iostream>
#include "Node.h"

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	m_root = nullptr;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other)
{
	m_root = new Node<T>(*(other.m_root));
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	deleteTree(m_root);
}


template <typename T>
void BinarySearchTree<T>::add(T value)
{
	add(value, this->m_root);
}

template <typename T>
void BinarySearchTree<T>::printTree(Order order)
{
	if(m_root == nullptr)
	{
		std::cout << "You printed an empty tree! Try again!" << std::endl;
		return;
	}

	printTree(m_root, order);
}

template <typename T>
Node<T>* BinarySearchTree<T>::search(T value)
{
	if(m_root == nullptr)
	{
		return nullptr;
	}
	return (search(value, m_root));
}

template <typename T>
void BinarySearchTree<T>::add(T value, Node<T>* subtree)
{
	//if at the right location then add it
	if(subtree == nullptr)
	{
		subtree = new Node<T>();
		subtree->setValue(value);
		m_root = subtree;

	}
	//if less than, then go left
	else if(value < subtree->getValue())
	{
		if(subtree->getLeft() != nullptr)
		{
			add(value, subtree->getLeft());
		}
		else
		{
			Node<T>* temp = new Node<T>();
			temp->setValue(value);
			subtree->setLeft(temp);
		}
	}
	//if greater then then go right
	else
	{
		if(subtree->getRight() != nullptr)
		{
			add(value, subtree->getRight());
		}
		else
		{
			Node<T>* temp = new Node<T>();
			temp->setValue(value);
			subtree->setRight(temp);
		}
	}
}

template <typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* subtree)
{
	//if on a leaf then delete it and set it equal to nullptr
	if(subtree->getLeft() != nullptr)
	{
		deleteTree(subtree->getLeft());
	}
	if(subtree->getRight() != nullptr)
	{
		deleteTree(subtree->getRight());
	}
	delete subtree;

}

template <typename T>
Node<T>* BinarySearchTree<T>::search(T value, Node<T>* subtree)
{
	//value is equal then return this pointer
	if(value == subtree->getValue())
	{
		return subtree;
	}
	//if the value is less then but there is nothing to the left
	else if(subtree->getLeft() == nullptr  && value < subtree->getValue())
	{
		return nullptr;
	}
	//value is greater then but nothing to the right
	else if(subtree->getRight() == nullptr)
	{
		return nullptr;
	}
	else
	{
		//value is less than current go left
		if(value < subtree->getValue())
		{
			return (search(value, subtree->getLeft()));
		}
		//value is greater than current, go right
		else
		{
			return (search(value, subtree->getRight()));
		}
	}
}

template <typename T>
void BinarySearchTree<T>::printTree(Node<T>* subtree, Order order) const
{
	if(order == PRE_ORDER)
	{
		if(subtree == nullptr)
		{
			return;
		}
		std::cout << subtree->getValue() << " ";
		printTree(subtree->getLeft(), order);
		printTree(subtree->getRight(), order);
	}
	else if(order == IN_ORDER)
	{
		if(subtree == nullptr)
		{
			return;
		}
		printTree(subtree->getLeft(), order);
		std::cout << subtree->getValue() << " ";
		printTree(subtree->getRight(), order);
	}
	//post_order
	else
	{
		if(subtree == nullptr)
		{
			return;
		}
		printTree(subtree->getLeft(), order);
		printTree(subtree->getRight(), order);
		std::cout << subtree->getValue() << " ";
	}
}





















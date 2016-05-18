/*
*   @file   : Node.h
*   @author : Gehrig Keane
*   @date   : 2015.08.31
*   Purpose : The header file for the Node class
*/

#ifndef NODE_H
#define NODE_H

#include <iostream> /** NULL */

class Node
{
	public:

	Node();

	Node(int value, Node* next);

	int getValue();

	Node* getLeft();

	Node* getRight();

	void setValue(int value);

	void setLeft(Node* left);

	void setRight(Node* right);

	private:

	Node* m_left;
	Node* m_right;
	int m_value;
};

#endif  
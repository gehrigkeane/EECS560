/*
*	@file	: Node.h
*	@author	: Gehrig Keane
*	@date	: 2015.11.17
*	Purpose	: provide Node h
*/

#ifndef NODE_H
#define NODE_H

class Node {
	public:
		Node()						{ value = -1; order = 0; }
		Node(int val)				{ value = val; order = 0; }
		~Node()						{ if ( child != nullptr )	{ delete child; }
									  if ( right != nullptr )	{ delete right; } }

		int getValue()				{ return value; }
		int getOrder()				{ return order; }
		Node* getRight()			{ return right; }
		Node* getChild()			{ return child; }
		
		void setRight(Node* node)	{ right = node; }
		void setChild(Node* node)	{ child = node; }

		void pushRight(Node* node)	{ if (right != nullptr)	{ right->pushRight(node); }
									  else 					{ right = node; } }
		void pushChild(Node* node)	{ if ( child != nullptr ) 	{ child->pushRight(node); }
									  else 						{ child = node; }
									  order = node->getOrder() + 1; }

	private:
		int value = -1;
		int order = 0;
		Node* right = nullptr;
		Node* child = nullptr;
};

#endif

/*
*	@file	: main.cpp
*	@author	: Gehrig Keane
*	@date	: 2015.08.31
*	Purpose	: provide main functionality
*/
/*
		10
	-		-




								10				
				5								8
		17				2				n				40
	6		12		n		n						3		n

*/
#include <iostream>
#include "BinaryTree.h"

int main(int argc, char** argv)
{
	BinaryTree* tree = new BinaryTree();
	tree->build();

	delete tree;
	return 0;
}

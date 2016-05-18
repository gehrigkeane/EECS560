/*
*	@file	: BinarySearchTree.cpp
*	@author	: Gehrig Keane
*	@date	: 2015.9.28
*	Purpose	: Implementation fo the Binary Search Tree class
*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//				Lab Required Functions
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void BinarySearchTree::insert(int value, Leaf* subtree)
{
	//if at the right location then insert it
	if(subtree == nullptr)
	{
		subtree = new Leaf();
		subtree->setValue(value);
		m_root = subtree;

	}//if
	else if(value < subtree->getValue())
	{
		if(subtree->getLeft() != nullptr)
		{
			insert(value, subtree->getLeft());
		}
		else
		{
			Leaf* temp = new Leaf();
			temp->setValue(value);
			subtree->setLeft(temp);
		}
	}//else if
	else
	{
		if(subtree->getRight() != nullptr)
		{
			insert(value, subtree->getRight());
		}
		else
		{
			Leaf* temp = new Leaf();
			temp->setValue(value);
			subtree->setRight(temp);
		}
	}//else
}//insert

void BinarySearchTree::remove(const int& entry)
{
	bool success = false;
	m_root = removeSimple(m_root, entry, success);

	if ( success == false )
	{
		std::cout << "Value not found" << std::endl;
	}
}//remove - generic function call

Leaf* BinarySearchTree::removeSimple(Leaf* subtree, const int val, bool& success)
{
	if ( subtree == nullptr )
	{
		success = false;
		return nullptr;
	}//if - tree empty, return
	else if ( subtree->getValue() == val )
	{
		// remove node, return subtree without node
		subtree = remove(subtree);
		success = true;
		return subtree;
	}//else if - found value
	else if ( subtree->getValue() > val )
	{
		Leaf* tempPtr = removeSimple(subtree->getLeft(), val, success);
		subtree->setLeft(tempPtr);
		return subtree;
	}//else if - go left
	else
	{
		Leaf* tempPtr = removeSimple(subtree->getRight(), val, success);
		subtree->setRight(tempPtr);
		return subtree;
	}//else - go right
}//removeSimple - beginning of the removal rabbit hole

void BinarySearchTree::deletemin()
{
	bool success = false;
	if ( m_root != nullptr )
	{
		int valueToDelete = findMin(m_root);
		m_root = removeSimple(m_root, valueToDelete, success);
	}//if - not empty
}//deletemin

void BinarySearchTree::deletemax()
{
	bool success = false;
	if ( m_root != nullptr )
	{
		int valueToDelete = findMax(m_root);
		m_root = removeSimple(m_root, valueToDelete, success);
	}//if - not empty
}//deletemax

void BinarySearchTree::printTree(Order order)
{
	if ( m_root == nullptr )
	{
		std::cout << "The tree is empty" << std::endl;
		return;
	}//if - tree is empty

	printTree(m_root, order);
}//printTree - public function call

void BinarySearchTree::printTree(Leaf* subtree, Order order)
{
	if ( order == PRE_ORDER )
	{
		if ( subtree == nullptr )
		{
			return;
		}//if - default return case
		std::cout << subtree->getValue() << " ";
		printTree(subtree->getLeft(), order);
		printTree(subtree->getRight(), order);
	}//if - print preorder
	else if ( order == IN_ORDER )
	{
		if ( subtree == nullptr )
		{ return; }//if - default return case
		printTree(subtree->getLeft(), order);
		std::cout << subtree->getValue() << " ";
		printTree(subtree->getRight(), order);
	}//else if - print in order
	else
	{
		std::cout << "\nLevelorder:" << std::endl << std::endl;

		Leaf* temp_leaf;
		queue.enqueue(m_root);

		while ( !queue.isEmpty() )
		{
			temp_leaf = queue.peek();
			std::cout << temp_leaf->getValue() << " ";

			if ( temp_leaf->getLeft() != nullptr )
			{ queue.enqueue(temp_leaf->getLeft()); }//if - enqueue left child
			if ( temp_leaf->getRight() != nullptr )
			{ queue.enqueue(temp_leaf->getRight()); }//if - enqueue right child
			
			queue.dequeue();
		}//while - queue isn't empty

		std::cout << std::endl;
	}//else - print levelorder
}//printTree

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//				Helpers
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Leaf* BinarySearchTree::remove(Leaf* leaf_del)
{
	if ( leaf_del->isLeaf() )
	{
		delete leaf_del;
		leaf_del = nullptr;
		return leaf_del;
	}//if - is leaf
	else if ( ( leaf_del->getLeft() == nullptr && leaf_del->getRight() != nullptr ) || ( leaf_del->getLeft() != nullptr && leaf_del->getRight() == nullptr ) )
	{
		Leaf* temp_leaf;
		if ( leaf_del->getLeft() != nullptr )
		{
			temp_leaf = leaf_del->getLeft();
		}//if
		else
		{
			temp_leaf = leaf_del->getRight();
		}//else
		
		delete leaf_del;
		leaf_del = nullptr;
		return temp_leaf;
	}//else if - one child
	else
	{
		int successor;
		Leaf* tempPtr = removeLeft(leaf_del->getRight(), successor);
		leaf_del->setRight(tempPtr);
		leaf_del->setValue(successor);
	}//else - two children, located successor
}//remove - remove leaf from tree

Leaf* BinarySearchTree::removeLeft(Leaf* leaf_del, int& successor)
{
	if ( leaf_del->getLeft() == nullptr )
	{
		successor = leaf_del->getValue();
		return remove(leaf_del);
	}//if - located successor
	else
	{
		leaf_del->setLeft(removeLeft(leaf_del->getLeft(), successor));
		return leaf_del;
	}//else - continue
}//removeLeft - two child removal phase two

int BinarySearchTree::findMin(Leaf* subtree)
{
	if ( subtree->getLeft() == nullptr )
	{
		return subtree->getValue();
	}//if - end of left chain
	else
	{
		findMin(subtree->getLeft());
	}//else
	return 0;
}//findmin

int BinarySearchTree::findMax(Leaf* subtree)
{
	if ( subtree->getRight() == nullptr )
	{
		return subtree->getValue();
	}//if - end of right chain
	else
	{
		findMax(subtree->getRight());
	}//else
	return 0;
}//findmax


void BinarySearchTree::deleteTree(Leaf* subtree)
{
		
	if ( subtree->getLeft() != nullptr  )
	{
		deleteTree(subtree->getLeft());
	}//if - not on a leaf then delete it's left
	if ( subtree->getRight() != nullptr  )
	{
		deleteTree(subtree->getRight());
	}//if - not on a leaf then delete it's right
	delete subtree;
}//deleteTree - destroy objcets left-recursively

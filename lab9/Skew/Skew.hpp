/*
*	@file	: Skew.hpp
*	@author	: Gehrig Keane
*	@date	: 2015.11.09
*	Purpose	: skew heap implementation file
*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		Helper Functions
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Skew::build()
{
	std::ifstream fp;
	fp.open("data.txt");
	if ( !fp )
	{
		std::cout << "\nFailed to open 'data.txt', please ensure file exists!" << std::endl;
		return;
	}
	std::string line;
	while ( std::getline(fp, line) )
	{
		std::stringstream  lineStream(line);
		int value;
		while ( lineStream >> value )
		{
			insert(value);
		}//while - strings in the stream
	}//while - lines in the file
	fp.close();
}//build

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		Skew Heap Functions
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Skew::insert(int val)
{
	if ( m_root == nullptr )
	{
		Hnode* n_node = new Hnode(val);
		m_root = n_node;
		return;
	}//if - heap is empty

	Hnode* n_node = new Hnode(val);
	m_root = concat(m_root, n_node);	
}//insert

Hnode* Skew::concat(Hnode* a, Hnode* b)
{
	if ( a == nullptr && b == nullptr )
		return nullptr;									//if - a and b = nullptr
	else if (a == nullptr)
		return b;										//else if - a is empty return b
	else if (b == nullptr)
		return a;										//else if - b is empty return a
	else
	{
		if ( a->getValue() > b->getValue() )
			return concat(b, a);						//if - a > b then swap
		else
		{
			if ( a->getRight() == nullptr )
				a->setRight(b);							//if - right subheap is empty
			else
				a->setRight(concat(a->getRight(), b));	//else - recurse
		}//else - concatenate on right subheap
	}//else - two valid heaps
	
	a->swap();
	return a;
}//concatenate

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		Print Functions
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Skew::print(Order order)
{
	if ( m_root == nullptr )
	{
		std::cout << "The Heap is empty" << std::endl;
		return;
	}//if - heap is empty return

	if ( order == PRE_ORDER )
		preorder(m_root);
	else if ( order == IN_ORDER )
		inorder(m_root);
	else if ( order == LEVEL_ORDER )
		levelorder();
	else
		std::cout << "\nPlease invoke print with appropriate enumerated key\n";
	std::cout << std::endl;
}//print

void Skew::preorder(Hnode* node)
{
	if (node == nullptr) { return; }	//Break on empty
	std::cout << node->getValue() << " ";
	preorder(node->getLeft());
	preorder(node->getRight());
}//preorder

void Skew::inorder(Hnode* node)
{
	if (node == nullptr) { return; }	//Break on empty
	inorder(node->getLeft());
	std::cout << node->getValue() << " ";
	inorder(node->getRight());
}//inorder

void Skew::levelorder()
{
	if (m_root == nullptr) { return; }	//Break on empty

	std::cout << std::endl;
	List* queue = new List();
	int current_level = 0;
	int next_level = 0;

	queue->push(m_root);
	current_level=1;

	while(!queue->isEmpty())
	{
		std::cout << queue->peek()->getValue() << " ";
		if (queue->peek()->getLeft() != nullptr)
		{
			queue->push(queue->peek()->getLeft());
			next_level++;
		}//if - left != null then push (increment next level)
		if (queue->peek()->getRight() != nullptr)
		{
			queue->push(queue->peek()->getRight());
			next_level++;
		}//if - right != null then push (increment next level)

		queue->pop();
		current_level--;
		if ( current_level == 0 )
		{
			std::cout << std::endl;
			current_level = next_level;
			next_level = 0;
		}//if - level current level completes print endl and transition
	}//while - queue isn't empty
}//levelorder

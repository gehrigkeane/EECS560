/*
*	@file	: Binomial.hpp
*	@author	: Gehrig Keane
*	@date	: 2015.11.17
*	Purpose	: provide Binomial Queue functionality
*/

void Binomial::build()
{
	std::ifstream fp;
	fp.open("data.txt");
	if ( !fp )
	{
		std::cout << "\nFailed to open 'data.txt', please ensure file exists!" << std::endl;
		return;
	}//if - file failed to open - check exists
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

void Binomial::Merge(Node* b)
{
	if (queue[b->getOrder()] == nullptr)
		queue[b->getOrder()] = b;
	else 
	{
		int order = b->getOrder();

		if (queue[b->getOrder()]->getValue() < b->getValue())
		{
			queue[b->getOrder()]->pushChild(b);
			Merge(queue[b->getOrder()]);
		}//if - merge b with queue
		else
		{
			b->pushChild(queue[b->getOrder()]);
			Merge(b);
		}//else - merge queue with b
		queue[order] = nullptr;
	}//else - queue not empty
}//merge - merge b with self (a)

void Binomial::deleteMin()
{
	Node* balance = nullptr;
	for (int i = 0; i < size; i++)
	{
		if ( queue[i] != nullptr && ( balance == nullptr || queue[i]->getValue() < balance->getValue() ) )
		{
			balance = queue[i];
			queue[i] = nullptr;
		}//if - unbalance detected
	}//for - search for unbalance

	if ( balance != nullptr )
	{
		Node* temp = balance->getChild();
		Node* next = nullptr;
		while(temp != nullptr)
		{
			next = temp->getRight();
			temp->setRight(nullptr);
			Merge(temp);
			temp = next;
		}//while - loop through merge process
	}//if - balance detected then proceed

}//deletemin

void Binomial::levelorder()
{
	std::cout << "Levelorder:" << "\n--------------------\n";
	for (int i = 0; i < size; i++)
	{
		if(queue[i] != nullptr)
		{
			std::cout << queue[i]->getValue() << std::endl;
			if (queue[i]->getChild() != nullptr)
				right->push(queue[i]->getChild());
			while (!right->isEmpty())
			{
				std::cout << right->peek()->getValue() << " ";
				if (right->peek()->getChild() != nullptr)
					child->push(right->peek()->getChild());
				if (right->peek()->getRight() != nullptr)
					right->push(right->peek()->getRight());
				
				right->pop();
				if (right->isEmpty() && !child->isEmpty())
				{
					std::cout << std::endl;
					right = child;
					child = new List();
				}//if - end of path
			}//while - no more right children
			std::cout << "\n--------------------\n";
		}//if - element != empty
	}//for - every array element
}//levelorder

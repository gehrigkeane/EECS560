/*
*	@file	: List.hpp
*	@author	: Gehrig Keane
*	@date	: 2015.09.21
*	Purpose	: simple list implementation from lab 1
*/

List::List()
{
	m_size = 0;
	m_front = nullptr;
}//List Default Constructor

List::~List()
{
	while(!isEmpty())
	{
		removeFront();
	}//while
}//List Default Destructor

bool List::isEmpty() const
{
	if (m_size == 0)
		return true;
	else
		return false;
}//isEmpty - bool check whether list is empty or not

int List::size() const
{
	return (m_size);
}//size - return size of list

bool List::search(int value) const
{
	Node* temp = m_front;

	if (!isEmpty())
	{
		for(temp=m_front;(temp->getNext())!=nullptr;temp=temp->getNext())
		{
			if (temp->getValue()==value)
			{
				return true;
			}//if - value = temp->value
		}//for - 
		if (temp->getValue()==value)
		{
			return true;
		}//if - value = temp->value
	}//if - list isn't empty
	return false;
}//search - traverse the linked list and return bool depending on if the argument is within the list

void List::printList() const
{
	Node* temp = m_front;
	if (!isEmpty())
	{
		for(int i = 0;i < m_size;i++)
		{
			std::cout << temp->getValue() << " ";
			temp = temp->getNext();
		}//for
		std::cout << std::endl;
	}//if - 
	else
		std::cout << "List Empty." << std::endl;
}//printList - print the linked list to the console

void List::addBack(int value)
{
	if(isEmpty())
	{
		m_front = new Node();
		m_front->setValue(value);
		m_front->setNext(nullptr);
	}//if - list is empty therefore, create first node
	else
	{
		Node* newNode = new Node();
		newNode->setValue(value);
		newNode->setNext(nullptr);

		Node* temp = m_front;
		if((temp->getNext()) != nullptr)
		{
			for(temp=m_front;(temp->getNext())!=nullptr;temp=temp->getNext());
			temp->setNext(newNode);
		}//if - 
		else
		{
			temp->setNext(newNode);
		}//else - 
	}//else - list has elements
	m_size++;
}//addBack - add node to the back of the list

void List::addFront(int value)
{
	if(isEmpty())
	{
		m_front = new Node();
		m_front->setValue(value);
		m_front->setNext(nullptr);
	}//if - list is empty therefore, create first node
	else
	{
		Node* newNode = new Node();
		newNode->setValue(value);
		newNode->setNext(m_front);
		m_front = newNode;
	}//else - list has elements
	m_size++;
}//addFront - add node to the front of the list

bool List::removeBack()
{
	if(isEmpty())
	{
		std::cout << "There are no values to remove" << std::endl;
		return false;
	}//if - display emptiness
	else if (m_size == 1)
	{
		return removeFront();
	}//elseif - 
	else
	{
		Node* temp = m_front;
		Node* temp1 = m_front;
		for(temp=m_front;((temp->getNext())->getNext())!=nullptr;temp=temp->getNext());
		temp1 = temp->getNext();
		temp->setNext(nullptr);
		delete temp1;
	}//else - list is not empty therefore, continue
	m_size--;
	return true;
}//removeBack - remove the end node from the list

int List::pop()
{
	int val = m_front->getValue();
	removeFront();
	return val;
}

void List::push(int x)
{
	addBack(x);
}//push - lovely wrapper

bool List::removeFront()
{
	if(isEmpty())
	{
		std::cout << "There are no values to remove" << std::endl;
		return false;
	}//if - display emptiness
	else if(m_size == 1)
	{
		Node* temp = m_front;
		m_front = nullptr;
		delete temp;
	}//else - list is not empty therefore, continue
	else
	{
		Node* temp = m_front;
		m_front = m_front->getNext();
		delete temp;
	}//else - 
	m_size--;
	return true;
}//removeFront - remove the front node from the list

bool List::erase(int value)
{
	Node* node = Find(value);
	if ( nullptr != node )
	{
		if ( 1 == m_size )
		{
			m_front = nullptr;
			m_size--;
			delete node;
			return true;
		}//if - only one node
		else if ( m_front == node )
		{
			m_front = node->getNext();
			m_size--;
			delete node;
			return true;
		}//else if - n > 1 and value is in front 
		else
		{
			Node* front = m_front;
			for(front=m_front; (front->getNext())!=nullptr; front=front->getNext())
			{
				if ( front->getNext() == node )
				{
					Node* back = node->getNext();
					front->setNext(back);
					delete node;
					m_size--;
					return true;
				}//if - value = front->value
			}//for - move to pointer before deletion node 
		}//else - node has front value
	}//if - value was found in the list
	return false;
}//erase - remove values from the list

Node* List::Find(int value) const
{
	Node* temp = m_front;

	if ( !isEmpty() )
	{
		for(temp=m_front;(temp->getNext())!=nullptr;temp=temp->getNext())
		{
			if ( temp->getValue() == value )
			{
				return temp;
			}//if - value = temp->value
		}//for - 
		if ( temp->getValue() == value )
		{
			return temp;
		}//if - value = temp->value
	}//if - list isn't empty
	return nullptr;
}//Find - traverse the linked list and return bool depending on if the argument is within the list
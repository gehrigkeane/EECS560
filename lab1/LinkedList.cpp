/*
*	@file	: LinkedList.cpp
*	@author	: Gehrig Keane
*	@date	: 2015.08.24
*	Purpose	: Linked List class implementation
*/

#include "LinkedList.h"

LinkedList::LinkedList()
{
	m_size = 0;
	m_front = nullptr;
}//LinkedList Default Constructor

LinkedList::~LinkedList()
{
	while (!isEmpty())
	{
		erase(m_front->getValue());
	}//while
}//LinkedList Default Destructor

void LinkedList::insert(int value)
{
	if ( isEmpty() )
	{
		m_front = new Node(value, nullptr);
		m_size++;
		std::cout << value << " added to the list\n";
	}//if - list is empty, create first node
	else if ( nullptr == Find(value) )
	{
		Node* newNode = new Node(value, nullptr);

		Node* temp = m_front;
		if ( nullptr != (temp->getNext()) )
		{
			for(temp=m_front;(temp->getNext())!=nullptr;temp=temp->getNext());
			temp->setNext(newNode);
		}//if - move to end of list
		else
			temp->setNext(newNode);
		m_size++;
		std::cout << value << " added to the list\n";
	}//else - list has elements
	else
		std::cout << "Value already exists in the list";
}//insert - add node to the back of the list

bool LinkedList::isEmpty() const
{
	if ( 0 == m_size )
		return true;
	else
		return false;
}//isEmpty - bool check whether list is empty or not

char* LinkedList::erase(int value)
{
	//Required due to string restrictions
	char* ret1 = "Value not found";
	char* ret2 = "Node deleted";
	char* ret3 = "Deletion failed";

	Node* node = Find(value);
	if ( nullptr == node )
		return ret1;
	else
	{
		if ( 1 == m_size )
		{
			m_front = nullptr;
			m_size--;
			delete node;
			return ret2;
		}//if - only one node
		else if ( m_front == node )
		{
			m_front = node->getNext();
			m_size--;
			delete node;
			return ret2;
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
					return ret2;
				}//if - value = front->value
			}//for - move to pointer before deletion node 
		}//else - node has front value
		return ret3;
	}//else - value was found in the list
}//erase - remove valuse from the list

void LinkedList::print() const
{
	Node* temp = m_front;
	if ( !isEmpty() )
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
}//print - print the linked list to the console

Node* LinkedList::Find(int value) const
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

int LinkedList::size() const
{
	return m_size;
}//size - return size of list
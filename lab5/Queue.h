/*
*	@file	: Queue.h
*	@author	: Gehrig Keane
*	@date	: 2015.9.28
*	Purpose	: Implementation of the Queue class
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "Container.h"
#include "Leaf.h"

class Queue {
	public:
		//Constructors-Destructors
		Queue() : m_front(nullptr), m_back(nullptr), size(0) {}
		~Queue() { while ( !( isEmpty() ) ) { dequeue(); } }

		//Accessors
		bool isEmpty() { return size == 0; };
		Leaf* peek() const { return m_front->getValue(); }

		//Queue functionality
		void enqueue(Leaf* val)
		{
			Container* temp = new Container(val);
			if ( !isEmpty() ) 
			{
				m_back->setNext(temp);
				m_back = temp;
			}//if - queue isn't empty
			else 
			{
				m_front = temp;
				m_back = m_front;
			}//else - queue is empty, start queue
			size++;
		}//enqueue

		void dequeue()
		{
			if ( !(isEmpty()) ) 
			{
				Container* temp = m_front;
				m_front = temp->getNext();
				delete temp;
				size--;
			}//if - queue not empty remove front
		}//dequeue
	
	private:
		Container* m_front;
		Container* m_back;
		int size;
};

#endif

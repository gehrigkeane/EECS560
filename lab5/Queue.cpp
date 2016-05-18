#include <exception>
#include "Leaf.h"

Queue::Queue() : m_front(nullptr), m_back(nullptr), size(0) {
}

Queue::~Queue() {
	while (!(isEmpty())) {
		dequeue();
	}
}

bool Queue::isEmpty() const {
	return size == 0;
}

void Queue::enqueue(Leaf* newValue) {
	Container* newContainerPtr = new Container(newValue);
	if (isEmpty()) {
		m_front = newContainerPtr;
		m_back = m_front;
	}
	else {
		m_back -> setNext(newContainerPtr);
		m_back = newContainerPtr;
	}

	size++;
}

void Queue::dequeue() {
	if (!(isEmpty())) {
		Container* temp = m_front;
		m_front = temp -> getNext();

		delete temp;

		size--;
	}
}

/** Only call after having checked that the queue is not empty */
Leaf* Queue::peek() const {
	return m_front -> getItem();
}

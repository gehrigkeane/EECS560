/*
*	@file	: CHash.hpp
*	@author	: Gehrig Keane
*	@date	: 2015.9.14
*	Purpose	: Closed CHash class implementation
*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		Lab Required Functions - public
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ins CHash::insert(long x)
{
	if (contains(x))
		return DUPLICATE;

	long index = 0;

	//std::cout << "Load factor: " <<  (float(active + 1) / float(m_size)) << std::endl;
	float current_load = float(active + 1) / float(m_size);
	if (current_load > load)
	{
		return LOAD;
	}//if - Load factor reached
	else
	{
		//insert new value
		CNode* temp = m_front;
		for(long i = 0; i < m_size; i++)
		{
			temp = m_front;
			index = hash(x, i);
			//std::cout << "Val: " << i << " CHash: " << index << std::endl;

			for (long k = 0; k < index; k++)
				temp = temp->getNext();
			if (temp->getValue() == -1)
			{
				//std::cout << "Inserting value at: " << i << std::endl;
				temp->setValue(x);
				active++;
				return SUCCESS;
			}
			else if (temp->getValue() == x)
				i = m_size;		// duplicate precaution - really should never happen
			//else keep going while CHash = -1 with true flag
		}//for each entry in the CHash table (mod makes this cycle through every element)
	}
	return END;
}//insert

bool CHash::remove(long x)
{
	CNode* temp = m_front;
	long index = 0;
	for(long i = 0; i < m_size; i++)
	{
		temp = m_front;
		index = hash(x, i);
		//std::cout << "Val: " << i << " CHash: " << index << std::endl;
		for (long k = 0; k < index; k++)
			temp = temp->getNext();
		if ((temp->getValue() == -1) && (temp->getFlag() == false))
		{
			std::cout << "No value to remove" << i << std::endl;
			return true;
		}
		else if (temp->getValue() == x)
		{
			temp->setValue(-1);
			temp->setFlag(true);
			active--;
			return true;
		}
		//else keep going while CHash = -1 with true flag
	}//for each entry in the CHash table (mod makes this cycle through every element)
	return false;
}//remove

void CHash::print() const
{
	CNode* temp = m_front;
	std::cout << "\nLoad: " << load << std::endl;;
	if (!isEmpty())
	{
		for(long i = 0;i < m_size;i++)
		{
			std::cout << i << ": " << temp->getValue() << " flag = ";
			if (temp->getFlag())
				std::cout << "true" << std::endl;
			else
				std::cout << "false" << std::endl;
			temp = temp->getNext();
		}//for
		std::cout << std::endl;
	}//if - 
	else
		std::cout << "CHash Empty." << std::endl;
}//print - print CHash table

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		Lab Required Functions - private
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool CHash::contains(long x)
{
	CNode* temp = m_front;
	long index = 0;
	for(long i = 0; i < m_size; i++)
	{
		temp = m_front;

		index = hash(x, i);
		for (long k = 0; k < index; k++)
			temp = temp->getNext();

		if ((temp->getValue() == -1) && (temp->getFlag() == false))
			return false;
		else if (temp->getValue() == x)
			return true;
		//else keep going while CHash = -1 with true flag
	}//for each entry in the CHash table (mod makes this cycle through every element)
	return false;
}//contains - true, false etc...

bool CHash::isfull()
{
	CNode* temp = m_front;
	for(long i; i < m_size; i++)
	{
		if (temp->getValue() == -1)
			return false;
		temp = temp->getNext();
	}
	return true;
}//isFull

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		Helpers
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void CHash::scrub()
{
	CNode* temp = m_front;
	for (long i = 0; i < m_size; i++)
	{
		temp->setValue(-1);
		temp->setFlag(false);
		temp = temp->getNext();
	}//for - scrub CHash
	active = 0;
}//scrub - cleans CHash table

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//				Embedded List Implementation
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void CHash::addBack(long value)
{
	if(isEmpty())
	{
		m_front = new CNode();
		m_front->setValue(value);
		m_front->setNext(nullptr);
	}//if - CHash is empty therefore, create first CNode
	else
	{
		CNode* newCNode = new CNode();
		newCNode->setValue(value);
		newCNode->setNext(nullptr);

		CNode* temp = m_front;
		if((temp->getNext()) != nullptr)
		{
			for(temp=m_front;(temp->getNext())!=nullptr;temp=temp->getNext());
			temp->setNext(newCNode);
		}//if - 
		else
		{
			temp->setNext(newCNode);
		}//else - 
	}//else - CHash has elements
	m_size++;
}//addBack - add CNode to the back of the CHash

bool CHash::removeFront()
{
	if(isEmpty())
	{
		std::cout << "There are no values to remove" << std::endl;
		return false;
	}//if - display emptiness
	else if(m_size == 1)
	{
		CNode* temp = m_front;
		m_front = nullptr;
		delete temp;
	}//else - CHash is not empty therefore, continue
	else
	{
		CNode* temp = m_front;
		m_front = m_front->getNext();
		delete temp;
	}//else - 
	m_size--;
	return true;
}//removeFront - remove the front CNode from the CHash

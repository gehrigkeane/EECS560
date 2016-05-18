/*
*	@file	: Hash.hpp
*	@author	: Gehrig Keane
*	@date	: 2015.9.14
*	Purpose	: Hash class implementation
*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		Constructors-Destructors
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Hash::Hash()
{
	m_size = 0;
	active = 0;
	m_front = nullptr;
}//Hash Default Constructor

Hash::Hash(int m)
{
	m_size = 0;
	active = 0;
	m_front = nullptr;

	for(int i = 0; i < m; i++)
	{
		addBack(-1);
	}//for
}//Hash Default Constructor

Hash::~Hash()
{
	while(!isEmpty())
	{
		removeFront();
	}//while
}//Hash Default Destructor

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		Lab Required Functions - public
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool Hash::insert(int x)
{
	if (contains(x))
		return false;

	int index = 0;

	std::cout << "Load factor: " <<  (float(active + 1) / float(m_size)) << std::endl;
	if ((float(active + 1) / float(m_size)) > 0.5)
	{
		Hash* tempList = new Hash();
		Node* temp = m_front;
		for (int i = 0; i < m_size; i++)
		{
			if (temp->getValue() != -1)
				tempList->addBack(temp->getValue());
			temp = temp->getNext();
		}//for - gather hashed data
		tempList->addBack(x);

		//scrub hash
		scrub();
		//reset active
		active = 0;
		//adjust list for new bucket size (after calculating next prime #)
		adjust(getPrime(m_size));

		for ( ; !tempList->isEmpty(); )
		{
			int val = tempList->pop();

			for(int i = 0; i < m_size; i++)
			{
				temp = m_front;
				index = hash(val, i);

				for (int k = 0; k < index; k++)
					temp = temp->getNext();

				if (temp->getValue() == -1)
				{
					temp->setValue(val);
					active++;
					//break loop
					i = m_size;
				}
				//else keep going while hash = -1 with true flag
			}//for each entry in the hash table (mod makes this cycle through every element)
		}//for - while tempList is not empty
		
		delete tempList;
		return true;
	}//if - rehash everything!
	else
	{
		//insert new value
		Node* temp = m_front;
		for(int i = 0; i < m_size; i++)
		{
			temp = m_front;
			index = hash(x, i);
			//std::cout << "Val: " << i << " hash: " << index << std::endl;

			for (int k = 0; k < index; k++)
				temp = temp->getNext();
			if (temp->getValue() == -1)
			{
				//std::cout << "Inserting value at: " << i << std::endl;
				temp->setValue(x);
				active++;
				return true;
			}
			else if (temp->getValue() == x)
				i = m_size;		// duplicate precaution - really should never happen
			//else keep going while hash = -1 with true flag
		}//for each entry in the hash table (mod makes this cycle through every element)
	}
	return false;
}//insert

bool Hash::remove(int x)
{
	Node* temp = m_front;
	int index = 0;
	for(int i = 0; i < m_size; i++)
	{
		temp = m_front;
		index = hash(x, i);
		//std::cout << "Val: " << i << " hash: " << index << std::endl;
		for (int k = 0; k < index; k++)
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
		//else keep going while hash = -1 with true flag
	}//for each entry in the hash table (mod makes this cycle through every element)
	return false;
}//remove

void Hash::print() const
{
	Node* temp = m_front;
	std::cout << "\n";
	if (!isEmpty())
	{
		for(int i = 0;i < m_size;i++)
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
		std::cout << "Hash Empty." << std::endl;
}//print - print hash table

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		Lab Required Functions - private
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool Hash::contains(int x)
{
	Node* temp = m_front;
	int index = 0;
	for(int i = 0; i < m_size; i++)
	{
		temp = m_front;

		index = hash(x, i);
		for (int k = 0; k < index; k++)
			temp = temp->getNext();

		if ((temp->getValue() == -1) && (temp->getFlag() == false))
			return false;
		else if (temp->getValue() == x)
			return true;
		//else keep going while hash = -1 with true flag
	}//for each entry in the hash table (mod makes this cycle through every element)
	return false;
}//contains - true, false etc...

bool Hash::isfull()
{
	Node* temp = m_front;
	for(int i; i < m_size; i++)
	{
		if (temp->getValue() == -1)
			return false;
		temp = temp->getNext();
	}
	return true;
}//isFull

int Hash::hash(int x, int i)
{
	return ((x + i) % m_size);
}//hash

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		Accessors
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int Hash::getActive() const
{
	return active;
}//active - returns active nodes (those holding meaningful values)

bool Hash::isEmpty() const
{
	if (m_size == 0)
		return true;
	else
		return false;
}//isEmpty - bool check whether Hash is empty or not

int Hash::size() const
{
	return (m_size);
}//size - return size of Hash

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		Helpers
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Hash::adjust(int newsize)
{
	for ( ; m_size < newsize; )
	{
		addBack(-1);
	}//for
}//adjust - stitch on new bins

int Hash::getPrime(int i)
{
	int j = 2 * i;
	for ( ; !isPrime(j); j++);
	return j;
}//getPrime - calls is prime for psooible prime numbers 

bool Hash::isPrime(int i)
{
	for(int k = 2; k < i; k++)
	{
		if (i % k == 0) return false;
	}//for
	return true;
}//isPrime - checks if i is prime

void Hash::scrub()
{
	Node* temp = m_front;
	for (int i = 0; i < m_size; i++)
	{
		temp->setValue(-1);
		temp->setFlag(false);
		temp = temp->getNext();
	}//for - scrub hash
}//scrub - cleans hash table

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//				Embedded List Implementation
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Hash::addBack(int value)
{
	if(isEmpty())
	{
		m_front = new Node();
		m_front->setValue(value);
		m_front->setNext(nullptr);
	}//if - Hash is empty therefore, create first node
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
	}//else - Hash has elements
	m_size++;
}//addBack - add node to the back of the Hash

int Hash::pop()
{
	int val = m_front->getValue();
	removeFront();
	return val;
}//pop - returns first node value and destroys first node

bool Hash::removeFront()
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
	}//else - Hash is not empty therefore, continue
	else
	{
		Node* temp = m_front;
		m_front = m_front->getNext();
		delete temp;
	}//else - 
	m_size--;
	return true;
}//removeFront - remove the front node from the Hash

/*
*	@file	: OHash.hpp
*	@author	: Gehrig Keane
*	@date	: 2015.9.21
*	Purpose	: OHash class implementation
*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		Constructors-Destructors
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
OHash::OHash(float max_load)
{
	load = max_load;
	m_front = nullptr;
	active = 0;
	m_size = 0;
}//OHash Default Constructor

OHash::OHash(float max_load, long m)
{
	load = max_load;
	m_size = 0;
	active = 0;
	m_front = nullptr;

	for(long i = 0; i < m; i++)
	{
		addBack();
	}//for
}//OHash Default Constructor

OHash::~OHash()
{
	while(!isEmpty())
	{
		removeFront();
	}//while
}//OHash Default Destructor

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//			Workspace
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

bool OHash::remove(long x)
{
	Core* temp = m_front;
	long index = hash(x);

	//std::cout << "Val: " << i << " hash: " << index << std::endl;
	for (long k = 0; k < index; k++)
		temp = temp->getNext();

	if ( temp->getList() == nullptr )
	{
		return true;
	}//if - no list exists
	else
	{
		List* list_temp = temp->getList();
		if ( list_temp->erase(x) )
		{
			active--;
			return true;
		}//if removal succeeded return true

		if ( list_temp->isEmpty() )
		{
			temp->setList(nullptr);
			delete list_temp;
		}//if - no more elements in list then delete list
	}//else - a list exists to erase from
	return false;
}//remove

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//				Lab Required Functions
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool OHash::find(long x)
{
	Core* temp = m_front;
	long index = hash(x);

	//Retrieve indicie
	for (long k = 0; k < index; k++)
		temp = temp->getNext();

	//Continue with logic
	if ( temp->getList() == nullptr )
		return false;
	else
	{
		if ((temp->getList())->search(x))
			return true;
	}
	return false;
}//find - true, false etc...

long OHash::hash(long x)
{
	return (x % m_size);
}//hash

Ins OHash::insert(long x)
{
	if (find(x))
		return DUPLICATE;

	//std::cout << "Load factor: " <<  (float(active + 1) / float(m_size)) << std::endl;
	
	if ((float(active + 1) / float(m_size)) > load)
		return LOAD;
	else
	{
		//std::cout << "No rehashing" << std::endl;
		Core* temp = m_front;
		long index = hash(x);
		//std::cout << "Index: " << index << std::endl;

		for (long k = 0; k < index; k++)
			temp = temp->getNext();

		List* list = temp->getList();
		if ( list == nullptr )
		{
			//std::cout << "Creating new list" << std::endl;
			List* list_temp = new List();
			list_temp->push(x);
			temp->setList(list_temp);
			active++;
		}
		else if ( !list->search(x) )
		{
			list->push(x);
			active++;
		}
	}
	return SUCCESS;
}//insert

void OHash::print() const
{
	Core* temp = m_front;
	std::cout << "\n";
	if (!isEmpty())
	{
		for(long i = 0;i < m_size;i++)
		{
			std::cout << i << ": ";
			if (temp->getList() == nullptr)
				std::cout << std::endl;
			else
				(temp->getList())->printList();
			temp = temp->getNext();
		}//for
		std::cout << std::endl;
	}//if - 
	else
		std::cout << "OHash Empty." << std::endl;
}//print - print hash table

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//				Helpers
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void OHash::adjust(long newsize)
{
	for ( ; m_size < newsize; )
	{
		addBack();
	}//for
}//adjust - stitch on new bins

long OHash::getPrime(long i)
{
	long j = 2 * i;
	for ( ; !isPrime(j); j++);
	return j;
}//getPrime - calls is prime for psooible prime numbers 

bool OHash::isPrime(long i)
{
	for(long k = 2; k < i; k++)
	{
		if (i % k == 0) return false;
	}//for
	return true;
}//isPrime - checks if i is prime

bool OHash::isEmpty() const
{
	if (m_size == 0)
		return true;
	else
		return false;
}//isEmpty - bool check whether OHash is empty or not

void OHash::rehash(long x)
{
	//Collect hashed data
	List* list_hash = new List();
	Core* temp = m_front;
	for (long i = 0; i < m_size; i++)
	{
		List* list_temp = temp->getList();
		if (list_temp != nullptr)
			while(!list_temp->isEmpty())
			{
				list_hash->push(list_temp->pop());
			}//while list isn't empty
			temp->setList(nullptr);
			delete list_temp;
		temp = temp->getNext();
	}//for - gather hashed data
	list_hash->push(x);

	std::cout << "\nList:" << std::endl;
	list_hash->printList();

	//scrub hash
	scrub();
	//adjust list for new bucket size (after calculating next prime #)
	adjust(getPrime(m_size));

	while ( !list_hash->isEmpty() )
	{
		insert(list_hash->pop());
	}
	
	delete list_hash;
}//rehash

void OHash::scrub()
{
	Core* temp = m_front;
	for (long i = 0; i < m_size; i++)
	{
		List* list_temp = temp->getList();
		if (list_temp != nullptr)
		{
			temp->setList(nullptr);
			delete list_temp;
		}//if - double check for memory leaks!
		temp = temp->getNext();
	}//for - scrub hash
	active = 0;
}//scrub - cleans hash table

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//				Embedded List Implementation
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void OHash::removeFront()
{
	if(isEmpty())
	{
		std::cout << "There are no values to remove" << std::endl;
	}//if - display emptiness
	else if(m_size == 1)
	{
		Core* temp = m_front;
		List* list_temp = temp->getList();
		m_front = nullptr;

		if ( list_temp != nullptr )
			delete list_temp;

		delete temp;
	}//else - OHash is not empty therefore, continue
	else
	{
		Core* temp = m_front;
		List* list_temp = temp->getList();
		m_front = m_front->getNext();

		if ( list_temp != nullptr )
			delete list_temp;

		delete temp;
	}//else - 
	m_size--;
}//removeFront - remove the front node from the OHash*/

void OHash::addBack()
{
	if(isEmpty())
	{
		m_front = new Core();
	}//if - OHash is empty therefore, create first Core
	else
	{
		Core* newCore = new Core();
		Core* temp = m_front;

		if((temp->getNext()) != nullptr)
		{
			for(temp=m_front;(temp->getNext())!=nullptr;temp=temp->getNext());
			temp->setNext(newCore);
		}//if - 
		else
		{
			temp->setNext(newCore);
		}//else - 
	}//else - OHash has elements
	m_size++;
}//addBack - add node to the back of the OHash

/*
*	@file	: Hash.hpp
*	@author	: Gehrig Keane
*	@date	: 2015.9.21
*	Purpose	: Hash class implementation
*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		Constructors-Destructors
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Hash::Hash()
{
	m_front = nullptr;
	active = 0;
	m_size = 0;
}//Hash Default Constructor

Hash::Hash(int m)
{
	m_size = 0;
	active = 0;
	m_front = nullptr;

	for(int i = 0; i < m; i++)
	{
		addBack();
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
//			Workspace
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

bool Hash::remove(int x)
{
	Core* temp = m_front;
	int index = hash(x);

	//std::cout << "Val: " << i << " hash: " << index << std::endl;
	for (int k = 0; k < index; k++)
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
bool Hash::find(int x)
{
	Core* temp = m_front;
	int index = hash(x);

	//Retrieve indicie
	for (int k = 0; k < index; k++)
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

int Hash::hash(int x)
{
	return (x % m_size);
}//hash

bool Hash::insert(int x)
{
	if (find(x))
		return false;

	std::cout << "Load factor: " <<  (float(active + 1) / float(m_size)) << std::endl;
	if ((float(active + 1) / float(m_size)) > 1)
		rehash(x);
	else
	{
		std::cout << "No rehashing" << std::endl;
		Core* temp = m_front;
		int index = hash(x);
		std::cout << "Index: " << index << std::endl;

		for (int k = 0; k < index; k++)
			temp = temp->getNext();

		List* list = temp->getList();
		if ( list == nullptr )
		{
			std::cout << "Creating new list" << std::endl;
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
	return false;
}//insert

void Hash::print() const
{
	Core* temp = m_front;
	std::cout << "\n";
	if (!isEmpty())
	{
		for(int i = 0;i < m_size;i++)
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
		std::cout << "Hash Empty." << std::endl;
}//print - print hash table

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//				Helpers
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Hash::adjust(int newsize)
{
	for ( ; m_size < newsize; )
	{
		addBack();
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

bool Hash::isEmpty() const
{
	if (m_size == 0)
		return true;
	else
		return false;
}//isEmpty - bool check whether Hash is empty or not

void Hash::rehash(int x)
{
	//Collect hashed data
	List* list_hash = new List();
	Core* temp = m_front;
	for (int i = 0; i < m_size; i++)
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

void Hash::scrub()
{
	Core* temp = m_front;
	for (int i = 0; i < m_size; i++)
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
void Hash::removeFront()
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
	}//else - Hash is not empty therefore, continue
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
}//removeFront - remove the front node from the Hash*/

void Hash::addBack()
{
	if(isEmpty())
	{
		m_front = new Core();
	}//if - Hash is empty therefore, create first Core
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
	}//else - Hash has elements
	m_size++;
}//addBack - add node to the back of the Hash
























































/*//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		Lab Required Functions - public
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




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



int Hash::size() const
{
	return (m_size);
}//size - return size of Hash

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		Helpers
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




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
}//removeFront - remove the front node from the Hash*/

/*
*	@file	: CHash.h
*	@author	: Gehrig Keane
*	@date	: 2015.9.14
*	Purpose	: Closed implementation of the hash class header
*/

#ifndef CHASH_H
#define CHASH_H

#include <iostream> /** NULL */
#include "CNode.h" /****/

enum Ins {DUPLICATE, LOAD, SUCCESS, END};

class CHash
{
	public:
	//Constructors-Destructors
	CHash(float max_load)			{ load = max_load; m_size = 0; active = 0; m_front = nullptr; }
	CHash(float max_load, long m)	{ load = max_load; m_size = 0; active = 0; m_front = nullptr; for(long i = 0; i < m; i++) { addBack(-1); } }
	~CHash()	{ while(!isEmpty()) { removeFront(); } }

	//Lab Required Functions - public
	Ins insert(long x);
	bool remove(long x);
	void print() const;

	//Accessors-Mutators
	void setLoad(float val)	{ load = val; }
	long getActive()   const { return active; }
	long size()		  const { return m_size; }
	bool isEmpty()	  const { if (m_size == 0) { return true; } return false; }
	void scrub();

	private:
	//Lab Required Functions - public
	bool contains(long x);
	bool isfull();
	long hash(long x, long i)	{ return ((x + i) % m_size); }

	//Helpers
	void adjust(long newsize) { for ( ; m_size < newsize; ) { addBack(-1); } }
	long getPrime(long i)	{ long j = 2*i; for ( ; !isPrime(j); j++); return j; }
	bool isPrime(long i)	{ for(long k = 2; k < i; k++) { if (i % k == 0) return false; } return true; }

	//Embedded list Mutators
	void addBack(long value);
	bool removeFront();
	long pop() { long val = m_front->getValue(); removeFront(); return val; }

	CNode* m_front;
	long active;
	long m_size;
	float load;
};
#include "CHash.hpp"
#endif

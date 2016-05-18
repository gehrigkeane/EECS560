/*
*	@file	: OHash.h
*	@author	: Gehrig Keane
*	@date	: 2015.9.21
*	Purpose	: implementation of the hash class header
*/

#ifndef HASH_H
#define HASH_H

#include <iostream> /** NULL */
#include "CHash.h"
#include "Core.h" /****/

class OHash
{
	public:
	//Constructors-Destructors
	OHash(float max_load);
	OHash(float max_load, long m);
	~OHash();

	//Lab Required Functions - public
	Ins insert(long x);
	bool remove(long x);
	void print() const;
	void scrub();

	//Accessors-Mutators
	void setLoad(float val)	{ load = val; }
	//long getActive() const;
	//long size() const;

	private:
	//Lab Required Functions - public
	bool find(long x);
	//bool isfull();
	long hash(long x);

	//Helpers
	void adjust(long newsize);
	long getPrime(long i);
	bool isPrime(long i);
	bool isEmpty() const;
	void rehash(long x);

	//Embedded list Mutators
	void addBack();
	//long pop();
	void removeFront();

	Core* m_front;
	long active;
	long m_size;
	float load;
};
#include "OHash.hpp"
#endif

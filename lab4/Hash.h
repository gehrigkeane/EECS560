/*
*	@file	: Hash.h
*	@author	: Gehrig Keane
*	@date	: 2015.9.21
*	Purpose	: implementation of the hash class header
*/

#ifndef HASH_H
#define HASH_H

#include <iostream> /** NULL */
#include "Core.h" /****/

class Hash
{
	public:
	//Constructors-Destructors
	Hash();
	Hash(int m);
	~Hash();

	//Lab Required Functions - public
	bool insert(int x);
	bool remove(int x);
	void print() const;

	//Accessors
	//int getActive() const;
	//int size() const;

	private:
	//Lab Required Functions - public
	bool find(int x);
	//bool isfull();
	int hash(int x);

	//Helpers
	void adjust(int newsize);
	int getPrime(int i);
	bool isPrime(int i);
	bool isEmpty() const;
	void rehash(int x);
	void scrub();

	//Embedded list Mutators
	void addBack();
	//int pop();
	void removeFront();

	Core* m_front;
	int active;
	int m_size;
};
#include "Hash.hpp"
#endif

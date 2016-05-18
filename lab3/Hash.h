/*
*	@file	: Hash.h
*	@author	: Gehrig Keane
*	@date	: 2015.9.14
*	Purpose	: implementation of the hash class header
*/

#ifndef HASH_H
#define HASH_H

#include <iostream> /** NULL */
#include "Node.h" /****/

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
	int getActive() const;
	bool isEmpty() const;
	int size() const;

	private:
	//Lab Required Functions - public
	bool contains(int x);
	bool isfull();
	int hash(int x, int i);

	//Helpers
	void adjust(int newsize);
	int getPrime(int i);
	bool isPrime(int i);
	void scrub();

	//Embedded list Mutators
	void addBack(int value);
	int pop();
	bool removeFront();

	Node* m_front;
	int active;
	int m_size;
};
#include "Hash.hpp"
#endif

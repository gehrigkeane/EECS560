/*
*	@file	: main.cpp
*	@author	: Gehrig Keane
*	@date	: 2015.10.19
*	Purpose	: provide main functionality
*/

#include <iostream>
#include <limits>
#include "Heap.h"

void printMenu();
int sterileInt();

int main(int argc, char** argv)
{
	Heap* heap = new Heap();
	heap->bottomUp();

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//				Runtime Input
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	int flag = 0;
	int prompt = 0;
	int inputPrompt = 0;

	while(flag!=-1)
	{
		printMenu();
		prompt = sterileInt();
		switch(prompt)
		{
			case 1:
				std::cout << "\nPlease insert the number that you want to be inserted in the heap\n\n";
				inputPrompt = sterileInt();
				heap->insert(inputPrompt);
				break;
			case 2:
				std::cout << "\nPlease insert the number that you want to remove from the 5-Heap\n\n> ";
				inputPrompt = sterileInt();
				heap->remove(inputPrompt);
				break;
			case 3:
				heap->deleteMin();
				break;
			case 4:
				heap->deleteMax();
				break;
			case 5:
				heap->levelorder();
				break;
			case 6:
				flag = -1;
				break;
			default: 
				std::cout << "\nInvalid choice" << std::endl; 
				prompt = 0;
				break;
		}
	}//while - decision structure loop
	
	delete heap;
	return 0;
}//main


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//				Helper Functions
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void printMenu()
{
	std::cout << "\n......................................."
			<< "\n\nPlease choose one of the following commands:\n\n"
			<< "1- insert\n\n"
			<< "2- remove\n\n"
			<< "3- deleteMin\n\n"
			<< "4- deleteMax\n\n"
			<< "5- levelorder\n\n"
			<< "6- exit\n\n"
			<< "> ";
}//printMenu

int sterileInt()
{
	int var = 0;
	while ( !(std::cin >> var) )
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid choice" << std::endl;
	}//while - not good input

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return (var);
}//sterileInt

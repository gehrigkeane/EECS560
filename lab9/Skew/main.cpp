/*
*	@file	: main.cpp
*	@author	: Gehrig Keane
*	@date	: 2015.11.09
*	Purpose	: main file
*/

#include "skew.h"
#include <iostream>
#include <limits>

void printMenu();
int sterileInt();

int main(int argc, char* argv[]){
	
	Skew* heap = new Skew();
	heap->build();
	
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
				std::cout << "\nPlease enter a number\n\n";
				inputPrompt = sterileInt();
				heap->insert(inputPrompt);
				break;
			case 2:
				heap->deleteMin();
				break;
			case 3:
				heap->print(PRE_ORDER);
				break;
			case 4:
				heap->print(IN_ORDER);
				break;
			case 5:
				heap->print(LEVEL_ORDER);
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
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//				Helper Functions
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void printMenu()
{
	std::cout << "\n......................................."
			<< "\n\nPlease choose one of the following commands:\n\n"
			<< "1- insert\n\n"
			<< "2- deleteMin\n\n"
			<< "3- preorder\n\n"
			<< "4- inorder\n\n"
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

/*
*	@file	: main.cpp
*	@author	: Gehrig Keane
*	@date	: 2015.11.17
*	Purpose	: provide main functionality
*/

#include "Binomial.h"
#include <iostream>
#include <limits>

void printMenu();
int sterileInt();

int main(int argc, char* argv[]){
	
	Binomial* bq = new Binomial();
	bq->build();

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
				std::cout << "\nNumber to be inserted\n\n";
				inputPrompt = sterileInt();
				bq->insert(inputPrompt);
				break;
			case 2:
				bq->deleteMin();
				break;
			case 3:
				bq->levelorder();
				break;
			case 4:
				flag = -1;
				break;
			default: 
				std::cout << "\nInvalid choice" << std::endl; 
				prompt = 0;
				break;
		}
	}//while - decision structure loop
	
	delete bq;
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
			<< "3- levelorder\n\n"
			<< "4- exit\n\n"
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
/*
*	@file	: main.cpp
*	@author	: Gehrig Keane
*	@date	: 2015.08.24
*	Purpose	: provide main functionality
*/
#include <iostream>
#include <limits>
#include <fstream>
#include "LinkedList.h"
#include "Node.h"

void printMenu();
int sterileInt();

int main()
{
	int flag = 0;
	int treePrompt = 0;
	int inputPrompt = 0;
	LinkedList* newList = new LinkedList();

	int value;
	FILE* fp = fopen("data.txt", "r");
	while ( EOF != fscanf(fp, "%d", &value) )
	{
		newList->insert(value);
	}//while - read int isn't EOF
	fclose(fp);

	while(flag!=-1)
	{
		printMenu();
		treePrompt = sterileInt();
		switch(treePrompt)
		{
			case 1:
				std::cout << "\nChoose a number to be inserted to the list:\n\n> ";
				inputPrompt = sterileInt();
				newList->insert(inputPrompt);
				break;
			case 2:
				std::cout << "\nChoose a number to be deleted from the list:\n\n> ";
				inputPrompt = sterileInt();
				std::cout << newList->erase(inputPrompt);
				break;
			case 3:
				std::cout << "\nList: ";
				newList->print();
				break;
			case 4:
				flag = -1;
				std::cout << "Exiting program . . ." << std::endl;
				break;
			default: 
				std::cout << "\nInvalid choice" << std::endl; 
				treePrompt = 0;
				break;
		}
	}//while - decision structure loop

	delete newList;
	return 0;
}//main

void printMenu()
{
	std::cout << "\n\n......................................."
			<< "\n\nPlease choose one of the following commands:\n\n"
			<< "1- insert\n\n"
			<< "2- erase\n\n"
			<< "3- print\n\n"
			<< "4- exit\n\n"
			<< "\n\n\n> ";
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
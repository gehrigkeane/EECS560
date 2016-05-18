/*
*	@file	: main.cpp
*	@author	: Gehrig Keane
*	@date	: 2015.9.28
*	Purpose	: main
*/

#include <iostream>
#include <limits>
#include <stdlib.h>
#include <string.h>	 //for strtok
#include "BinarySearchTree.h"

void printMenu();
int sterileInt();

int main() {

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//			Initialize arrays with m
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	char line[1024];
	char* tok;
	int m = 0;
	FILE* fp = fopen("data.txt","r");

	if (fgets(line, sizeof line, fp) == NULL)
	{
		return 1;
	}//if - bad file input exit execution

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//			Tokenize file input
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	m = std::atoi(strtok (line," ,.-"));
	
	BinarySearchTree tree;
	tree.insert(m);

	tok = strtok (NULL, " ,.-");
	while (tok != nullptr)
	{
		//~~~~~~~~~~Build Simple Linked hash Here~~~~~~~~~~
		//Assumes good integer values from file
		tree.insert(std::atoi(tok));
		tok = strtok (NULL, " ,.-");
	}//catch remaining tokens on first line

	while (fgets(line, sizeof line, fp) != NULL)
	{
		tok = strtok (line," ,.-");
		while (tok != nullptr)
		{
			//~~~~~~~~~~Build Simple Linked hash Here~~~~~~~~~~
			//Assumes good integer values from file
			tree.insert(std::atoi(tok));
			tok = strtok (NULL, " ,.-");
		}//while - the line no longer has integers
	}//while - lines left in the file

	fclose(fp);

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//			  Runtime Input
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
				std::cout << "\nPlease insert the number that you want to be inserted in the tree\n\n> ";
				inputPrompt = sterileInt();
				tree.insert(inputPrompt);
				break;
			case 2:
				std::cout << "\nWhich number do you like to remove from the tree?\n\n> ";
				inputPrompt = sterileInt();
				tree.remove(inputPrompt);
				break;
			case 3:
				tree.deletemin();
				break;
			case 4:
				tree.deletemax();
				break;
			case 5:
				std::cout << "\npreorder: ";
				tree.printTree(PRE_ORDER);
				break;
			case 6:
				std::cout << "\ninorder: ";
				tree.printTree(IN_ORDER);
				break;
			case 7:
				tree.printTree(LEVEL_ORDER);
				break;
			case 8:
				flag = -1;
				std::cout << "Exiting program . . ." << std::endl;
				break;
			default: 
				std::cout << "\nInvalid choice" << std::endl; 
				prompt = 0;
				break;
		}
	}//while - decision structure loop
	
	return 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//			  Helper Functions
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void printMenu()
{
	std::cout << "\n......................................."
			<< "\n\nPlease choose one of the following commands:\n\n"
			<< "1- insert\n\n"
			<< "2- remove\n\n"
			<< "3- deletemin\n\n"
			<< "4- deletemax\n\n"
			<< "5- preorder\n\n"
			<< "6- inorder\n\n"
			<< "7- levelorder\n\n"
			<< "8- exit\n\n"
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

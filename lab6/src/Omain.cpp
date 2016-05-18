/*
*	@file	: main.cpp
*	@author	: Gehrig Keane
*	@date	: 2015.9.14
*	Purpose	: provide main functionality
*/

#include <iostream>
#include <limits>
#include <stdlib.h>
#include <string.h>		//for strtok
#include "OHash.h"

void printMenu();
int sterileInt();

int main(int argc, char** argv)
{
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//				Initialize arrays with m
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
	//				Tokenize file input
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	m = std::atoi(strtok (line," ,.-"));
	OHash* newhash = new OHash(m);

	tok = strtok (NULL, " ,.-");
	while (tok != nullptr)
	{
		//~~~~~~~~~~Build Simple Linked hash Here~~~~~~~~~~
		//Assumes good integer values from file
		newhash->insert(std::atoi(tok));
		tok = strtok (NULL, " ,.-");
	}//catch remaining tokens on first line

	while (fgets(line, sizeof line, fp) != NULL)
	{
		tok = strtok (line," ,.-");
		while (tok != nullptr)
		{
			//~~~~~~~~~~Build Simple Linked hash Here~~~~~~~~~~
			//Assumes good integer values from file
			newhash->insert(std::atoi(tok));
			tok = strtok (NULL, " ,.-");
		}//while - the line no longer has integers
	}//while - lines left in the file

	fclose(fp);

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
				std::cout << "\nWhich number do you want to insert into the hash table?\n\n> ";
				inputPrompt = sterileInt();
				newhash->insert(inputPrompt);
				break;
			case 2:
				std::cout << "\nWhich number do you want to remove from the hash table?\n\n> ";
				inputPrompt = sterileInt();
				std::cout << newhash->remove(inputPrompt);
				break;
			case 3:
				newhash->print();
				break;
			case 4:
				flag = -1;
				std::cout << "Exiting program . . ." << std::endl;
				break;
			default: 
				std::cout << "\nInvalid choice" << std::endl; 
				prompt = 0;
				break;
		}
	}//while - decision structure loop

	delete newhash;

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
			<< "2- delete\n\n"
			<< "3- print\n\n"
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

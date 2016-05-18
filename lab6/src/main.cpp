/*
*	@file	: main.cpp
*	@author	: Gehrig Keane
*	@date	: 2015.9.14
*	Purpose	: provide main functionality
*/

#include <iostream>
#include <limits>
#include <stdlib.h>
#include <string.h>
#include "OHash.h"
#include "CHash.h"
#include "Timer.cpp"

void printMenu();
int sterileInt();

int main(int argc, char** argv)
{
	Timer timer, timer_total;
	timer_total.start();

	float data_points[] = {0.2, 0.3, 0.4, 0.5, 0.6, 0.7};

	timer.start();
	CHash* closedhash = new CHash(0.2, 60011);
	std::cout << "\nClosed Hashing Initialization:\n";
	timer.printTime(timer.stop());

	for (int i = 1; i<6; i++)
	{
		std::cout << "\nClosedhash:\n\tSeed: " << i << std::endl;
		srand(i);

		for (int j = 0; j<6; j++)
		{
			std::cout << "\tLoad: " << data_points[j];
			closedhash->setLoad(data_points[j]);

			//Insertion Phase
			timer.start();
			while( closedhash->insert(rand() % 2147483647) != LOAD );
			timer.printTime(timer.stop());

			//Clean Hash
			closedhash->scrub();
			std::cout << std::endl;
		}//for - load factor values
	}//for - random seeds

	timer.start();
	OHash* openhash = new OHash(0.2, 60011);
	std::cout << "\nOpen Hashing Initialization:\n";
	timer.printTime(timer.stop());

	for (int i = 1; i<6; i++)
	{
		std::cout << "\nOpenhash:\n\tSeed: " << i << std::endl;
		srand(i);

		for (int j = 0; j<6; j++)
		{
			std::cout << "\tLoad: " << data_points[j];
			openhash->setLoad(data_points[j]);

			//Insertion Phase
			timer.start();
			while( openhash->insert(rand() % 2147483647) != LOAD );
			timer.printTime(timer.stop());

			//Clean Hash
			openhash->scrub();
			std::cout << std::endl;
		}//for - load factor values
	}//for - random seeds

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//				Runtime Input
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	timer.start();
	delete closedhash;
	delete openhash;
	std::cout << "\nCleaning up: ";
	timer.printTime(timer.stop());
	std::cout << std::endl;
	
	std::cout << "\nTotal Time: ";
	timer_total.printTime(timer_total.stop());
	std::cout << std::endl;
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

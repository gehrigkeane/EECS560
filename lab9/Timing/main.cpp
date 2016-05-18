/*
*	@file	: main.cpp
*	@author	: Gehrig Keane
*	@date	: 2015.11.09
*	Purpose	: main timing implementation file
*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include "leftist.h"
#include "skew.h"
#include "Timer.cpp"

long n[] = {50000, 100000, 200000, 400000};
void print_times(double times[][5]);

int main(int argc, char* argv[]){
	Timer ti, ti_total;
	//ti_total.start();

	Leftist* leftist = new Leftist();
	Skew* skew = new Skew();


	double times[4][5];

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//		Leftist Build Timing
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	std::cout << "\nLeftist:";
	for (int i = 1; i < 6; i++)
	{
		std::cout << setw(10) << i << " ";
		srand(i);

		for (int j = 0; j < 4; j++)
		{
			//Clean Data Structure
			delete leftist; leftist = new Leftist(); ti.start();

			//Generate Data
			double rand_n[n[j]];
			for (int k = 0; k < n[j]; k++)
				rand_n[k] = rand() % (4*n[j]);

			//Build Data Structure
			for(int k = 0; k < n[j]; k++)
				leftist->insert(rand_n[k]);

			times[j][i-1] = ti.stop();
		}//for - values of n
	}//for - random seeds

	print_times(times);

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//		Skew Build Timing
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	std::cout << "\nSkew   :";
	for (int i = 1; i < 6; i++)
	{
		std::cout << setw(10) << i << " ";
		srand(i);

		for (int j = 0; j < 4; j++)
		{
			//Clean Data Structure
			delete skew; skew = new Skew(); ti.start();

			//Generate Data
			double rand_n[n[j]];
			for (int k = 0; k < n[j]; k++)
				rand_n[k] = rand() % (4*n[j]);

			//Build Data Structure
			for(int k = 0; k < n[j]; k++)
				skew->insert(rand_n[k]);

			times[j][i-1] = ti.stop();
		}//for - values of n
	}//for - random seeds

	print_times(times);

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//		Leftist Delete/Insert Timing
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	std::cout << "\nL Times:";
	for (int i = 1; i < 6; i++)
	{
		std::cout << setw(10) << i << " ";
		srand(i);

		for (int j = 0; j < 4; j++)
		{
			//Clean Data Structure
			delete leftist; leftist = new Leftist();

			//Generate Data
			double rand_n[n[j]];
			for (int k = 0; k < n[j]; k++)
				rand_n[k] = rand() % (4*n[j]);

			//Build Data Structure
			for(int k = 0; k < n[j]; k++)
				leftist->insert(rand_n[k]);

			ti.start();

			for (int k = 0; k < n[j]/10; k++)
			{
				double r = ((double) rand() / (RAND_MAX));
				if ( r < 0.5 )
					leftist->deleteMin();
				else
					leftist->insert(rand() % (4*n[j]));
			}//for - 10% of n

			times[j][i-1] = ti.stop();
		}//for - values of n
	}//for - seeds

	print_times(times);

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//		Skew Delete/Insert Timing
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	std::cout << "\nS Times:";
	for (int i = 1; i < 6; i++)
	{
		std::cout << setw(10) << i << " ";
		srand(i);

		for (int j = 0; j < 4; j++)
		{
			//Clean Data Structure
			delete skew; skew = new Skew();

			//Generate Data
			double rand_n[n[j]];
			for (int k = 0; k < n[j]; k++)
				rand_n[k] = rand() % (4*n[j]);

			//Build Data Structure
			for(int k = 0; k < n[j]; k++)
				skew->insert(rand_n[k]);

			ti.start();

			for (int k = 0; k < n[j]/10; k++)
			{
				double r = ((double) rand() / (RAND_MAX));
				if ( r < 0.5 )
					skew->deleteMin();
				else
					skew->insert(rand() % (4*n[j]));
			}//for - 10% of n

			times[j][i-1] = ti.stop();
		}//for - values of n
	}//for - seeds

	print_times(times);
} // end main

void print_times(double times[][5])
{
	for (int j = 0; j < 4; j++)									//for - values of n
	{
		std::cout << std::endl << setw(6) << n[j] << " :";		//print n value
		for (int i = 0; i < 5; i++)								//for - random seeds
			std::cout << setw(10) << times[j][i] << " ";		//print time values
	}
	std::cout << std::endl;
}//print_times
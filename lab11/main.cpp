/*
*   @file   : main.cpp
*   @author : Gehrig Keane
*   @date   : 2015.12.02
*   Purpose : main file functionality
*/

#include <iostream>
#include <fstream>
#include <string>
#include "MST.h"

int main()
{
	int val = 0, size = 0, graphs = 0;
	std::ifstream fp;
	MST* mst;

	fp.open("data.txt");
	fp >> graphs;
	
	for (int g = 0; g < graphs; g++)
	{
		fp >> size;
		int** matrix = new int*[size];
		matrix = mst->buildMatrix(fp, matrix, size, val);
		mst = new MST(matrix, size);
		
		std::cout << "Graph " << g+1 << ":\nKruskal: "; mst->kruskal();
		std::cout << "Prim: "; 							mst->prim();
		std::cout << std::endl;
		delete mst; mst = nullptr;
	}//for - each graph

	return 0;
}//main

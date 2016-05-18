/*
*   @file   : MST.h
*   @author : Gehrig Keane
*   @date   : 2015.12.02
*   Purpose : Minimum spanning tree header file
*/

#ifndef MST_
#define MST_

#include <iostream>
#include <fstream>
#include "eNode.h"
#include "Set.h"

class MST {
public:
	MST() {}
	MST(int** arr, int d)	{ m_arr = arr, size = d; }
	~MST()					{ for (int i = 0; i < size; i++)
							{ delete[] m_arr[i]; } 
							  delete[] m_arr; }
	void prim();
	void kruskal();
	int** buildMatrix(std::istream& fp, int** matrix, int s, int entry);

private:

	int size;
	int** m_arr;
	eNode** current;
	Set* edges_bucket;

	// --------------------------------------------------
	//	Helper Functions for simple operations
	// --------------------------------------------------
	void sort(eNode** current, int size);
	void update(eNode** current, int* vT);

	bool element(int elem, int* vT)
	{
		for (int i = 0; i < size; i++) { if (vT[i] == elem) { return true; } }
		return false;
	}//element

	eNode* deque(eNode** current, int size)
	{
		for (int i = 0; i < size; i++) { if (current[i] != nullptr) { return current[i]; } }
		return nullptr;
	}//deque


	bool isEmpty(eNode** current, int size)
	{
		for (int i = 0; i < size; i++) { if (current[i] != nullptr) { return true; } }
		return false;
	}//isEmpty - true if no elements in queue

	int countEdges()
	{
		int edge_count = 0;
		for (int i = 0; i < size; i++) { for (int j = i; j < size; j++) { if (m_arr[i][j] != 0) { edge_count++; } } }
		return edge_count;
	}//countEdges

	void setEdges()
	{
		int k = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = i; j < size; j++)
			{ if (m_arr[i][j] != 0) { current[k++] = new eNode(m_arr[i][j], i, j); } }
		}//for
	}//setEdges

	void print(eNode** e_node)
	{
		int cost = 0;
		for (int i = 0; i < size-1; i++)
		{
			std::cout << "(" << e_node[i]->getA() << ", " << e_node[i]->getB() << ") ";
			cost += e_node[i]->getCost();
		}
		std::cout << "Cost = " << cost << std::endl;
	}//print

	bool checkValid(eNode** e_node)
	{
		for (int i = 0; i < size-1; i++)
		{ if (e_node[i] == nullptr) { std::cout << "No Minimum Spanning Tree" << std::endl; return false; } }
		return true;
	}//checkSolution

	void clean(eNode** e_node) { for (int i = 0; i < size-1; i++) { e_node[i] = nullptr; } }//clean
};

#include "MST.hpp"
#endif

/*
*   @file   : MST.hpp
*   @author : Gehrig Keane
*   @date   : 2015.12.02
*   Purpose : Minimum spanning tree implementation
*/
#include <fstream>

void MST::prim()
{
	//clean e_node
	eNode** e_node = new eNode*[size-1];
	clean(e_node);

	//initialize vertice
	int* vert = new int[size];
	for (int i = 0; i < size; i++) { vert[i] = -1; }
	vert[0] = 0;

	//initialize current matrix
	current = new eNode*[size*size];
	int k = 0;
	for (int i = 1; i < size; i++) { if (m_arr[0][i] != 0) { current[k++] = new eNode(m_arr[0][i], 0, i); } }
	sort(current, size*size);

	//start prim
	eNode* x;
	int mark = 0;
	while ( isEmpty(current, size*size) && mark != size)
	{
		x = deque(current, size*size);
		e_node[mark] = x;
		vert[mark++ + 1] = x->getB();
		update(current, vert);
	}//while - queue isn't emtpy
	
	if (checkValid(e_node))
		print(e_node);
	delete[] vert;
	vert = nullptr;
	delete[] e_node;
	e_node = nullptr;
	delete[] current;
	current = nullptr;
}//prim

void MST::kruskal()
{
	edges_bucket = new Set(size);

	//initialize edges count 
	int edge_count = countEdges();
	current = new eNode*[edge_count];
	setEdges();

	//initialize current node
	for (int i = 0; i < edge_count; i++) { if (current[i] == nullptr) { break; } }
	sort(current, edge_count);
	
	//clean e_node
	eNode** e_node = new eNode*[size-1];
	clean(e_node);
	eNode* x;

	//start kruskal
	int mark = 0;
	int count = 0;
	while ( isEmpty(current, edge_count) && mark != size-1 )
	{
		x = current[count];
		current[count] = nullptr;

		if (edges_bucket->find(x->getA()) != edges_bucket->find(x->getB()))
		{
			e_node[mark] = x;
			edges_bucket->Union(x->getA(), x->getB());
			mark++;
		}//if
		count++;
	}//while - queue isn't empty

	if (checkValid(e_node))
		print(e_node);
	delete edges_bucket;
	edges_bucket = nullptr;
	delete[] e_node;
	e_node = nullptr;
	delete[] current;
	current = nullptr;
}//kruskal

// --------------------------------------------------
//	Longer helper funtions for structure operations
// --------------------------------------------------
void MST::sort(eNode** current, int size)
{
	eNode* swap;
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (current[j + 1] == nullptr || current[j]->getCost() > current[j + 1]->getCost())
			{
				swap = current[j];
				current[j] = current[j + 1];
				current[j + 1] = swap;
			}//if
		}//for
	}//for
}//sort

void MST::update(eNode** current, int* vT)
{
	for (int i = 0; i < size*size; i++)
		current[i] = nullptr;

	int k = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (m_arr[i][j] != 0 && element(i, vT) && !(element(j, vT)))
				current[k++] = new eNode(m_arr[i][j], i, j);
		}//for
	}//for
	sort(current, size*size);
}//update

int** MST::buildMatrix(std::istream& fp, int** matrix, int s, int val)
{
	for (int i = 0; i < s; i++)
	{
		matrix[i] = new int[s];
		for (int j = 0; j < s; j++)
		{
			fp >> val;
			matrix[i][j] = val;
		}//for - each col in the matrix
	}//for - each row in the matrix
	return matrix;
}//buildMatrix

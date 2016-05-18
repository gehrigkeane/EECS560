/*
*   @file   : sNode.h
*   @author : Gehrig Keane
*   @date   : 2015.12.02
*   Purpose : Set Node class header and functionality
*/

#ifndef SNODE_
#define SNODE_

class sNode
{
	public:
		sNode()							{ parent = nullptr; rank = 0; }
		sNode(int& val)					{ parent = nullptr; rank = 0; value = val; }

		void setValue(int& val)			{ value = val; }
		void setRank(const int r)		{ rank = r;}
		void setParent(sNode* par)		{ parent = par; }
		int getValue()					{ return value; }
		int getRank()					{ return rank; }
		sNode* getParent()				{ return parent; }

	private:
		int value;
		int rank;
		sNode* parent;
};

#endif

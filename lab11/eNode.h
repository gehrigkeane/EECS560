/*
*   @file   : eNode.h
*   @author : Gehrig Keane
*   @date   : 2015.12.02
*   Purpose : Edge Node header and implementation file
*/

#ifndef EDGE_
#define EDGE_

class eNode {
	public:
		eNode();
		eNode(int c, int x, int y) { cost = c; a = x; b = y; }

		int getA()			{ return a; }
		int getB()			{ return b; }
		int getCost()		{ return cost; }
		void setA(int x)	{ a = x; }
		void setB(int y)	{ b = y; }
		void setCost(int c)	{ cost = c; }

	private:
		int a;
		int b;
		int cost;
};

#endif

#ifndef DISJOINT_H
#define DISJOINT_H

#include <iostream>

class subset
{
	int parent,rank;
public:
	void setparent(int a)
	{
		parent=a;
	}
	int getparent()
	{
		return parent;
	}
	void setrank(int x)
	{
		rank=x;
	}
	int getrank()
	{
		return rank;
	}
};

class disjoint
{
	subset *s;
public:
	disjoint(int size)
	{
		s=new subset[size];
		for (int i = 0; i < size; ++i)
		{
			
			s[i].setparent(i);
			s[i].setrank(0);
		}
	}
	int find(int i)   
	{
		if(s[i].getparent()!=i)
			s[i].setparent(find(s[i].getparent()));
		return s[i].getparent();
	}
	void Union(int x, int y)
	{
		int xroot=find(x);
		int yroot=find(y);
		if (s[xroot].getrank()<s[yroot].getrank())
       		s[xroot].setparent(yroot);
    	else if (s[xroot].getrank() > s[yroot].getrank())
       	 	s[yroot].setparent(xroot);
       	 else
       	 {
       	 	s[yroot].setparent(xroot);
       	 	s[yroot].setrank(s[yroot].getrank()+1);
       	 }
	}
};
#endif

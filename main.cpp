#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "graph.h"
#include <fstream>
#include <string>


using namespace std;



int main()
{ 
  	int size=0,k,v=0;
	ifstream in;
	string data;
	char filename[20];	
	
	cout<<"Enter the file name you want to get data from"<<endl;
	cin>>filename;
	in.open(filename);

	while(getline(in,data))
	{
		size++;
	}
	
	in.close();
	ifstream fin;
	fin.open(filename);
	while(fin>>k)
	{
		if(k!=0)
			v++;
	}
	graph g(size,v/2);
	
	fin.close();
	in.open(filename);
	for(int i=0;i<size;i++)
	{
		for (int j = 0; j < size; ++j)
		{
			
			in>>k;
			if(k!=0)
			{
				g.addedge(i,j);
			}
		}
	}
	in.close();
	in.open(filename);
	edge ar[v/2];
	int n=0;
	for (int i = 0; i < size; ++i)
	{
		
		for (int j = 0; j < size; ++j)
		{
			
			in>>k;
			if(k!=0 && j>i)
			{
				ar[n++].create(i,j,k);
			}
		}
	}
	g.make(ar,n);
	
	
	
	
		g.Kruksal();
	
	
	
	return 0;
}

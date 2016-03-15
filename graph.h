#ifndef GRAPH_H
#define GRAPH_H
#include "linklist.h"

class edge
{
	int src;
	int dest;
	int weight;
public:
	edge()
	{
		src=-1;
		dest=-1;
		weight=-1;
	}
	edge(const edge &temp)
	{
		src=temp.src;
		dest=temp.dest;
		weight=temp.weight;
	}
	void create(int a,int b,int c)
	{
		src=a;
		dest=b;
		weight=c;
	}
	int getsource()
	{
		return src;
	}
	int getdest()
	{
		return dest;
	}
	int getweight()
	{
		return weight;
	}
};

class graph 
{
	private:
		int v,e;
		List *array;
		edge *edges;
	public:
		graph(int size, int ed);
		graph(const graph &temp);
		void addedge(int a, int b);
		void sortedges();

		void make(edge ar[], int size);
		int size()
		{
			return v;
		}
		void BFS(int s);
		void DFS(int s);
		void Kruksal();
		void print();
};

#endif

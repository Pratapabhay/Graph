#include "linklist.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "graph.h"
#include <stdlib.h>
#include <unistd.h>
#include "disjoint.h"
#include <time.h>  
using namespace std;

void wait ( int seconds ) 
{ 
  clock_t endwait; 
  endwait = clock () + seconds * CLOCKS_PER_SEC ; 
  while (clock() < endwait) {} 
} 

graph::graph(int size,int ed)
{
	v=size;
    e=ed;
	array=new List[v];
    edges=new edge[ed];
}

graph::graph(const graph &temp)
{
	v=temp.v;
    array=new List[v];
    memcpy(array,temp.array,v);
}

void graph::addedge(int a, int b)
{	
	array[a].Append(b);
}

void graph::make(edge ar[], int size)
{
    for(int i=0;i<size;i++)
    {
        edges[i]=ar[i];
    }
}

void graph::print()
{
	int i=0;
	while(i<v)
	{
		cout<<i<<"-->";
		array[i].Print();
		i++;
	}
}




void graph::Kruksal()
{
    cout<<endl; 
    cout<<"Kruksal's Algorithm- MST";
    sortedges();
    disjoint d(v);
    int i=0,j=0;
    

    while(i<v-1)
    {
        
        edge temp=edges[j];
        j++;
        if(d.find(temp.getsource())!=d.find(temp.getdest()))
        {
            d.Union(d.find(temp.getsource()),d.find(temp.getdest()));
            cout<<"Edge Added"<<temp.getsource()<<"->"<<temp.getdest()<<" : "<<temp.getweight()<<endl;
            wait(2);
             i++;
        }
    }
}

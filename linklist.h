#ifndef LINKLIST_H
#define LINKLIST_H
#include <iostream>
#include <stdio.h>
class Node 
{
private:
    int data;
    Node* next;

  public:
    Node(); 
    void SetData(int aData) { data = aData; };
    void SetNext(Node* aNext) { next = aNext; };
    int Data() { return data; };
    Node* Next() { return next; };
};

class List {
    Node *head;
  public:
    List();
    void Print();
    Node* rhead()
    {
        return head;
    }
    void Append(int data);
    void Delete(int data);
    Node* search(int data);
};
#endif

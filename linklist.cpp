#include <iostream>
#include <stdio.h>
#include "linklist.h"

using namespace std;
Node::Node()
{
	next=NULL;
}

List::List() 
{ 
	head = NULL; 
}

void List::Print() {

    
    Node *tmp = head;

    
    if ( tmp == NULL ) {
    cout << "EMPTY" << endl;
    return;
    }

    
    if ( tmp->Next() == NULL ) {
    cout << tmp->Data();
    cout << " --> ";
    cout << "NULL" << endl;
    }
    else {
    
    do {
        cout << tmp->Data();
        cout << " --> ";
        tmp = tmp->Next();
    }
    while ( tmp != NULL );

    cout << "NULL" << endl;
    }
}


void List::Append(int data) {

   
    Node* newNode = new Node;
    newNode->SetData(data);
    newNode->SetNext(NULL);

   
    Node *tmp = head;

    if ( tmp != NULL ) {
    
    while ( tmp->Next() != NULL ) {
        tmp = tmp->Next();
    }

   
    tmp->SetNext(newNode);
    }
    else {
   
    head = newNode;
    }
}


void List::Delete(int data) {

   
    Node *tmp = head;

   
    if ( tmp == NULL )
    return;

   
    if ( tmp->Next() == NULL ) {
    delete tmp;
    head = NULL;
    }
    else {
    
    Node *prev;
    do {
        if ( tmp->Data() == data ) break;
        prev = tmp;
        tmp = tmp->Next();
    } while ( tmp != NULL );

    
    prev->SetNext(tmp->Next());

    
    delete tmp;
    }
}

Node* List::search(int data)
{
	Node *temp;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->Data()==data)
			{
				break;
			}
			temp=temp->Next();
	}
	return temp;
}

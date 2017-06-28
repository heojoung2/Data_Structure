#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node *link;
};

class Linked_list
{
private:
	int length;
	Node *head;
public:
	Linked_list();
	int Get_length();
	void Display();

	bool Add(int index, int data);
	bool Delete(int index);
	int Search(int index);

	void Free();
};

#endif

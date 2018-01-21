#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include <iostream>

using namespace std;

class Node
{
public:
	float coefficient;
	int degree;

	Node *left_link;
	Node *right_link;
};

class Linked_list
{
private:
	int length;
	Node *head;
public:
	Linked_list();
	int Get_length();
	Node *Get_head();
	void Display();

	bool Add(float coefficient, int degree);
	bool Delete(int degree);

	void Free();
};

Linked_list Plus(Linked_list polynomial1, Linked_list polynomial2);

#endif
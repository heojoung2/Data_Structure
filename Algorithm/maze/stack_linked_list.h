#ifndef STACK_LINKED_LIST
#define STACK_LINKED_LIST

#include <iostream>
#include <string>

using namespace std;

class Data
{
private:
	int pos[2];
	Data *link;

public:
	Data() {};
	Data(int _pos[2]);
	int *Get_pos();
	Data *Get_link();
	void Set_link(Data *link);
	void initial(int val1, int val2);
};

class Stack
{
private:
	int length;
	Data *head;

public:
	Stack();
	~Stack();
	bool Empty();
	void Push(int val1, int val2);
	Data Pop();
	Data Peek();
	int Get_length();
	void Display();
};

#endif
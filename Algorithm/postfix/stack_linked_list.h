#ifndef STACK_LINKED_LIST
#define STACK_LINKED_LIST

#include <iostream>
#include <string>

using namespace std;

class Data
{
private:
	int value;
	Data *link;

public:	
	Data() {};
	Data(int _value);
	int Get_value();
	Data *Get_link();
	void Set_link(Data *link);
	void initial(int _value,Data *_link);
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
	void Push(Data *data);
	Data Pop();
	int Get_length();
};

#endif
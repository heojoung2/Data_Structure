#include <iostream>

using namespace std;

class Data
{
private:
	char data;
	Data *link;

public:	
	Data() {};
	Data(char _data);
	Data *Get_link();
	void Set_link(Data *link);
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
	bool Pop();
};

Data::Data(char _data)
	:data(_data),link(NULL)
{}


Data *Data::Get_link()
{
	return link;
}


void Data::Set_link(Data *_link)
{
	link = _link;
}

Stack::Stack()
	:length(0)
{
	head = new Data;
	head->Set_link(NULL);
}

Stack::~Stack()
{
	delete head;
}

bool Stack::Empty()
{
	if (head->Get_link() == NULL)
		return true;
	return false;
}

void Stack::Push(Data *data)
{
	data->Set_link(head->Get_link());
	head->Set_link(data);
	length++;
}

bool Stack::Pop()
{
	if (!Empty())
	{
		if (length == 1)
			head->Set_link(NULL);
		else
			head->Set_link(head->Get_link()->Get_link());

		length--;
		return true;
	}
	return false;
}

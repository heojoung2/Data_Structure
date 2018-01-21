#include "stack_linked_list.h"

using namespace std;

Data::Data(int _value)
	:value(_value), link(NULL)
{}

int Data::Get_value()
{
	return value;
}

Data *Data::Get_link()
{
	return link;
}


void Data::Set_link(Data *_link)
{
	link = _link;
}

void Data::initial(int _value, Data *_link)
{
	value = _value;
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

Data Stack::Pop()
{

	if (!Empty())
	{
		Data *result = head;
		result = head->Get_link();

		if (length == 1)
			head->Set_link(NULL);
		else
			head->Set_link(head->Get_link()->Get_link());

		length--;
		return *result;
	}
	else
	{
		cout << "Pop error" << endl;
		exit(1);
	}

}

int Stack::Get_length()
{
	return length;
}
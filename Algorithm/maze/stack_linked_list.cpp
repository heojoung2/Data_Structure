#include "stack_linked_list.h"

using namespace std;

Data::Data(int _pos[2])
	:link(NULL)
{
	pos[0] = _pos[0];
	pos[1] = _pos[1];
}

int *Data::Get_pos()
{
	return pos;
}

Data *Data::Get_link()
{
	return link;
}


void Data::Set_link(Data *_link)
{
	link = _link;
}

void Data::initial(int val1, int val2)
{
	pos[0] = val1;
	pos[1] = val2;
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

void Stack::Push(int val1, int val2)
{
	Data *data = new Data;

	data->initial(val1, val2);

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

Data Stack::Peek()
{

	if (!Empty())
	{
		Data *result = head;
		result = head->Get_link();

		return *result;
	}
	else
	{
		cout << "Peek error" << endl;
		//exit(1);
	}

}

int Stack::Get_length()
{
	return length;
}

void Stack::Display()
{
	Data *node = head->Get_link();

	while (node->Get_link() != NULL)
	{
		cout <<"["<< node->Get_pos()[0] <<" "<<node->Get_pos()[1]<<"]"<<endl;
		node = node->Get_link();
	}
	cout << "[" << node->Get_pos()[0] << " " << node->Get_pos()[1] << "]" << endl;

	cout << endl;
}
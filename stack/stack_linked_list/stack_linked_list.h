#include <iostream>

using namespace std;

template <typename T>
class Data
{
private:
	T data;
	Data *link;

public:	
	Data() {};
	Data(T _data);
	T Get_data();
	Data *Get_link();
	void Set_link(Data *link);
};

template <typename T>
class Stack
{
private:
	int length;
	Data<T> *head;

public:
	Stack();
	~Stack();
	bool Empty();
	void Push(Data<T> *data);
	Data<T> Pop();
	Data<T> Peek();
	void Display();
};

template <typename T>
Data<T>::Data(T _data)
	:data(_data),link(NULL)
{}

template <typename T>
T Data<T>::Get_data()
{
	return data;
}

template <typename T>
Data<T> *Data<T>::Get_link()
{
	return link;
}

template <typename T>
void Data<T>::Set_link(Data *_link)
{
	link = _link;
}

template <typename T>
Stack<T>::Stack()
	:length(0)
{
	head = new Data<T>;
	head->Set_link(NULL);
}

template <typename T>
Stack<T>::~Stack()
{
	delete head;
}

template <typename T>
bool Stack<T>::Empty()
{
	if (head->Get_link() == NULL)
		return true;
	return false;
}

template <typename T>
void Stack<T>::Push(Data<T> *data)
{
	data->Set_link(head->Get_link());
	head->Set_link(data);
	length++;
}

template <typename T>
Data<T> Stack<T>::Pop()
{
	if (!Empty())
	{
		Data<T> *result = head;
		result = head->Get_link();

		if (length == 1)
			head->Set_link(NULL);
		else
			head->Set_link(head->Get_link()->Get_link());

		length--;
		return *result;
	}
	else
		cout << "Pop 오류" << endl;
}

template <typename T>
Data<T> Stack<T>::Peek()
{
	if (!Empty())
	{
		return *(head->Get_link());
	}
	else
		cout << "Peek 오류" << endl;
}

template <typename T>
void Stack<T>::Display()
{
	Data<T> *node = head->Get_link();
	
	if (length == 0)
		cout << "빈 스택입니다" << endl;
	else
	{
		while (node->Get_link() != NULL)
		{
			cout << node->Get_data() << endl;
			node = node->Get_link();
		}
		cout << node->Get_data() << endl;
	}
	cout << endl;
}
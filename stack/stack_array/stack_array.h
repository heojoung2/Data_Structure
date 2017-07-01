#include <iostream>

using namespace std;

template <typename T>
class Data
{
private:
	T data;

public:
	Data() {};
	Data(T _data);
	T Get_data();
};

template <typename T>
class Stack
{
private:
	int max_size;
	int top;
	Data<T> *data_arr;

public:
	Stack(int _max_size);
	void Delete_stack();
	bool Full();
	bool Empty();
	bool Push(Data<T> data);
	Data<T> Pop();
	Data<T> Peek();
	void Display();
};

template <typename T>
Data<T>::Data(T _data)
	:data(_data)
{}

template <typename T>
T Data<T>::Get_data()
{
	return data;
}

template <typename T>
Stack<T>::Stack(int _max_size)
	:max_size(_max_size), top(0)
{
	data_arr = new Data<T>[_max_size];
}

template <typename T>
void Stack<T>::Delete_stack()
{
	delete data_arr;
}

template <typename T>
bool Stack<T>::Full()
{
	if (top == max_size)
		return true;
	return false;
}

template <typename T>
bool Stack<T>::Empty()
{
	if (top == 0)
		return true;
	return false;
}

template <typename T>
bool Stack<T>::Push(Data<T> data)
{
	if (!Full())
	{
		data_arr[top] = data;
		top++;
		return true;
	}
	else
		cout << "Push 에러" << endl;
		return false;
}

template <typename T>
Data<T> Stack<T>::Pop()
{
	if (!Empty())
	{
		top--;
		return data_arr[top + 1];
	}
	else
		cout << "Pop 에러" << endl;
}

template <typename T>
Data<T> Stack<T>::Peek()
{
	if (!Empty())
	{
		return data_arr[top];
	}
	else
		cout << "Peek 에러" << endl;
}

template <typename T>
void Stack<T>::Display()
{
	cout << "size : " <<top << endl;
	for (int i = 0; i < top; i++)
		cout  << i<<" : "<<data_arr[i].Get_data()<<endl;
	cout << endl;
}
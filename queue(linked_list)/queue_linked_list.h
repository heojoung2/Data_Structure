#include <iostream>

using namespace std;

template <typename T>
class Data
{
private:
	T data;
	Data *link;

public:
	Data();
	Data(T _data);
	T Get_data();
	void Set_link(Data *_link);
	Data *Get_link();
};

template <typename T>
class Queue
{
private:
	Data<T> *head;

public:
	Queue();
	~Queue();
	bool Is_empty();
	void Enqueue(Data<T> *_data);
	Data<T> Dequeue();
	Data<T> Peek();
	void Display();
};

template <typename T>
Data<T>::Data()
{}

template <typename T>
Data<T>::Data(T _data)
	:data(_data), link(NULL)
{}

template <typename T>
T Data<T>::Get_data()
{
	return data;
}

template <typename T>
void Data<T>::Set_link(Data *_link)
{
	link = _link;
}

template <typename T>
Data<T> *Data<T>::Get_link()
{
	return link;
}

template <typename T>
Queue<T>::Queue()
{
	head = new Data<T>;
	head->Set_link(NULL);
}

template <typename T>
Queue<T>::~Queue()
{
	delete head;
}

template <typename T>
bool Queue<T>::Is_empty()
{
	if (head->Get_link() == NULL)
		return true;
	return false;
}

template <typename T>
void Queue<T>::Enqueue(Data<T> *_data)
{
	Data<T> *node = head;

	while (node->Get_link() != NULL)
		node = node->Get_link();
	node->Set_link(_data);
}

template <typename T>
Data<T> Queue<T>::Dequeue()
{
	if (!Is_empty())
	{
		Data<T> *result = head->Get_link();

		if (result->Get_link() == NULL)
			head->Set_link(NULL);
		else
			head->Set_link(result->Get_link());

		return *result;
	}
	else
	{
		cout << "Dequeue error" << endl;
		exit(1);
	}
}

template <typename T>
Data<T> Queue<T>::Peek()
{
	if (!Is_empty())
	{
		Data<T> *result = head->Get_link();
		return *result;
	}
	else
	{
		cout << "Dequeue error" << endl;
		exit(1);
	}
}

template <typename T>
void Queue<T>::Display()
{
	Data<T> *node = head->Get_link();

	if (node == NULL)
		cout << "empty queue" << endl;
	else
	{
		while (node->Get_link() != NULL)
		{
			cout << node->Get_data() << " ";
			node = node->Get_link();
		}
		cout << node->Get_data() << endl;
	}
	cout << endl;
}
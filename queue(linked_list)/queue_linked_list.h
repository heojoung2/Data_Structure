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
	Data<T> *front;
	Data<T> *rear;
	int length;

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
	:length(0)
{
	front = new Data<T>;
	rear = new Data<T>;

	front->Set_link(NULL);
	rear->Set_link(NULL);
}

template <typename T>
Queue<T>::~Queue()
{
	delete front;
	delete rear;
}

template <typename T>
bool Queue<T>::Is_empty()
{
	if (front->Get_link() == NULL)
		return true;
	return false;
}

template <typename T>
void Queue<T>::Enqueue(Data<T> *_data)
{
	if (length == 0)
	{
		front->Set_link(_data);
		rear->Set_link(_data);
	}
	else
	{
		rear->Get_link()->Set_link(_data);
		rear->Set_link(_data);
	}
	length++;
}

template <typename T>
Data<T> Queue<T>::Dequeue()
{
	if (!Is_empty())
	{
		Data<T> *result = front->Get_link();

		if (result->Get_link() == NULL)
		{
			front->Set_link(NULL);
			rear->Set_link(NULL);
		}
		else
			front->Set_link(result->Get_link());

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
		Data<T> *result = front->Get_link();
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
	Data<T> *node = front->Get_link();

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
#ifndef LINEAR_QUEUE
#define	LINEAR_QUEUE

#include <iostream>

using namespace std;

template <typename T>
class Data
{
private:
	T data;

public:
	Data();
	Data(T _data);
	T Get_data();
};

template <typename T>
class Queue
{
private:
	Data<T> *data;
	int front;
	int rear;
	int max_size;

public:
	Queue(int max_size);
	~Queue();
	bool Is_enqueue();
	bool Is_dequeue();
	bool Enqueue(Data<T> data);
	Data<T> Dequeue();
	Data<T> Peek();
	void Display();
};

template <typename T>
Data<T>::Data()
{}

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
Queue<T>::Queue(int _max_size)
	:front(0),rear(0),max_size(_max_size)
{
	data = new Data<T>[max_size];
}

template <typename T>
Queue<T>::~Queue()
{
	delete data;
}

template <typename T>
bool Queue<T>::Is_enqueue()
{
	if (0 <= rear && rear < max_size && front <= rear)
		return true;
	return false;
}

template <typename T>
bool Queue<T>::Is_dequeue()
{
	if (0<=front && front<max_size && front<rear)
		return true;
	return false;
}

template <typename T>
bool Queue<T>::Enqueue(Data<T> _data)
{
	if (Is_enqueue())
	{
		data[rear++] = _data;
		return true;
	}
	else
	{
		cout << "Enqueue error" << endl;
		exit(1);
	}
}

template <typename T>
Data<T> Queue<T>::Dequeue()
{
	if (Is_dequeue())
	{
		return data[front++];
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
	if (Is_dequeue())
	{
		return data[front];
	}
	else
	{
		cout << "Peek error" << endl;
		exit(1);
	}
}

template <typename T>
void Queue<T>::Display()
{
	for (int i = front; i < rear; i++)
		cout << data[i].Get_data()<<" ";
	cout << endl;
}

#endif
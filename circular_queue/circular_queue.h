#ifndef QUEUE_ARRAY
#define	QUEUE_ARRAY

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
	int length;
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
	:front(0), rear(0),length(0), max_size(_max_size)
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
	if(length < max_size)
		return true;
	return false;
}

template <typename T>
bool Queue<T>::Is_dequeue()
{
	if (length > 0)
		return true;
	return false;
}

template <typename T>
bool Queue<T>::Enqueue(Data<T> _data)
{
	if (Is_enqueue())
	{
		if (rear == max_size)
			rear = 0;
		data[rear++] = _data;
		length++;
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
		if (front == max_size)
			front = 0;
		length--;
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
		if (front == max_size)
			front = 0;
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
{	if (front < rear)
	{
		for (int i = front; i < rear; i++)
			cout << data[i].Get_data() << " ";
	}
	else if (front >= rear)
	{
		int i;
		for(i=front;i<max_size;i++)
			cout << data[i].Get_data() << " ";
		for(i=0;i<rear;i++)
			cout << data[i].Get_data() << " ";
	}
	cout << endl;
}

#endif
#ifndef _MIN_HEAP_
#define _MIN_HEAP_

#include <iostream>
using namespace std;

class Min_heap
{
private:
	int *arr;
	int max_size;
	int current_size;
public:
	Min_heap(int _size);
	~Min_heap();
	void Insert(int value);
	int Delete();
	void Display();
};

#endif _MIN_HEAP_
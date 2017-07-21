#ifndef _MAX_HEAP_
#define _MAX_HEAP_

#include <iostream>
using namespace std;

class Max_heap
{
private:
	int *arr;
	int max_size;
	int current_size;
public:
	Max_heap(int _size);
	~Max_heap();
	void Insert(int value);
	int Delete();
	void Display();
};

#endif _MAX_HEAP
#include "min_heap.h"

int main()
{
	int size = 20;
	Min_heap min_heap(size);

	min_heap.Insert(40);
	min_heap.Insert(50);
	min_heap.Insert(20);
	min_heap.Insert(10);
	min_heap.Insert(30);
	min_heap.Insert(60);
	min_heap.Display();

	cout<<"Delete : "<<min_heap.Delete() << endl;
	min_heap.Display();
	cout << "Delete : " << min_heap.Delete() << endl;
	min_heap.Display();

	return 0;
}
#include "max_heap.h"

int main()
{
	int size = 20;
	Max_heap max_heap(size);

	max_heap.Insert(20);
	max_heap.Insert(10);
	max_heap.Insert(30);
	max_heap.Insert(40);
	max_heap.Insert(60);
	max_heap.Insert(50);
	max_heap.Display();

	cout<<"Delete : "<<max_heap.Delete() << endl;
	max_heap.Display();
	cout << "Delete : " << max_heap.Delete() << endl;
	max_heap.Display();

	return 0;
}
#include "linked_list.h"

int main()
{
	Linked_list polynomial1;
	Linked_list polynomial2;
	Linked_list result;

	polynomial1.Add(30, 3);
	polynomial1.Add(10, 1);
	polynomial1.Add(50, 5);
	polynomial1.Display();

	polynomial2.Add(10.5, 1);
	polynomial2.Add(20.5, 2);
	polynomial2.Add(30.5, 3);
	polynomial2.Add(40.5, 4);
	polynomial2.Display();

	result = Plus(polynomial1, polynomial2);
	result.Display();

	polynomial1.Free();
	polynomial2.Free();
	result.Free();

	return 0;
}

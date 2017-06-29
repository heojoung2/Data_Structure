#include "doubly_linked_list.h"

int main()
{
	Linked_list linked_list;

	linked_list.Add(0, 1);
	linked_list.Add(1, 2);
	linked_list.Add(2, 3);
	linked_list.Display();

	linked_list.Delete(1);
	linked_list.Display();

	cout<<"search(1) : "<<linked_list.Search(1) << endl;
	cout <<"length : " <<linked_list.Get_length() << endl;
	linked_list.Free();
	return 0;
}
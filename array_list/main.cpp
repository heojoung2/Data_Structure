#include "array_list.h"

int main()
{
	Array_list<int> array_list(5);
	
	array_list.Add(0, 2);
	array_list.Add_first(1);
	array_list.Add_last(3);
	array_list.Display();

	array_list.Delete(1);
	array_list.Delete_last();
	array_list.Display();

	array_list.Add_first(0);
	array_list.Add_last(3);
	array_list.Add(2,2);
	array_list.Display();

	cout << "search(2) : " << array_list.Search(2)<<endl;
	cout << "length : " << array_list.Get_length() << endl;

	array_list.Clear_array();
	array_list.Display();

	array_list.Delete_array();

	return 0;
}
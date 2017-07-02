#include "stack_linked_list.h"

int main()
{
	Stack<char> stack;
	Data<char> data1('a');
	Data<char> data2('b');
	Data<char> data3('c');
	
	stack.Push(&data1);
	stack.Display();

	stack.Push(&data2);
	stack.Push(&data3);
	stack.Display();
	
	stack.Pop();
	stack.Display();

	Data<char> data4 = stack.Peek();
	cout <<"Peek : "<< data4.Get_data() << endl<<endl;

	stack.Push(&data3);
	stack.Display();

	return 0;
}

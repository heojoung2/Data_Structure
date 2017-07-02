#include "stack_array.h"

int main()
{
	Stack<int> stack(10);
	Data<int> data1(1);
	Data<int> data2(2);

	stack.Push(data1);
	stack.Push(data2);
	stack.Display();

	stack.Pop();
	stack.Display();

	Data<int> data3 = stack.Peek();
	cout <<"Peek : "<< data3.Get_data() << endl;

	stack.Delete_stack();
	return 0;
}
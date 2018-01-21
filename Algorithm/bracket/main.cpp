#include "stack_linked_list.h"
#include <string>

int main()
{
	string input;
	cout << "input : ";
	cin >> input;

	Stack stack;

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '(')
		{
			Data data('(');
			stack.Push(&data);
		}
		else if (input[i] == ')')
		{
			if (!stack.Pop())
			{
				cout << "Fail" << endl;
				return 0;
			}
		}
	}
	if (stack.Empty())
		cout << "Success" << endl;
	else
		cout << "Fail" << endl;

	return 0;
}

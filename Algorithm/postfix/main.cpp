#include "stack_linked_list.h"

int main()
{
	int cnt = 0;
	char equation[] = "2 3 * 2 /";
	cout << "equation : "<<equation<<endl;
	
	Stack stack;
	char *token = strtok(equation," ");

	Data data[100];

	while (token!=NULL)
	{
		
		if (*token =='+')
		{
			Data operand1 = stack.Pop();
			Data operand2 = stack.Pop();
			Data result(operand2.Get_value() + operand1.Get_value());
			stack.Push(&result);
		}
		else if (*token == '-')
		{
			Data operand1 = stack.Pop();
			Data operand2 = stack.Pop();
			Data result(operand2.Get_value() - operand1.Get_value());
			stack.Push(&result);
		}
		else if (*token == '*')
		{
			Data operand1 = stack.Pop();
			Data operand2 = stack.Pop();
			Data result(operand2.Get_value() * operand1.Get_value());
			stack.Push(&result);
		}
		else if (*token == '/')
		{
			Data operand1 = stack.Pop();
			Data operand2 = stack.Pop();
			Data result(operand2.Get_value() / operand1.Get_value());
			stack.Push(&result);
		}
		else
		{
			int value = atoi(token);
			data[cnt].initial(value, NULL);
			stack.Push(&data[cnt++]);
		}		
		token = strtok(NULL, " ");
	}
	
	if (stack.Get_length() == 1)
		cout << "result : " << stack.Pop().Get_value() << endl;
	else
		cout << "error equation" << endl;
	
	return 0;
}

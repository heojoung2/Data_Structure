#include<iostream>

using namespace std;

int recursive_fibonacci(int value)
{
	int result = 0;
	if (value == 1 || value==2)
		result = 1;
	else
		result = recursive_fibonacci(value - 2) + recursive_fibonacci(value-1);
	return result;
}

int iterative_fibonacci(int value)
{
	int val1 = 1;
	int val2 = 1;

	for (int i = 2; i < value; i++)
	{
		val2 = val1 + val2;
		val1 = val2 - val1;
	}
	return val2;
}

int main()
{
	int value;
	while (true)
	{
		cout << "value : ";
		cin >> value;

		cout << "recursive_fibonacci : " << recursive_fibonacci(value) << endl;
		cout << "iterative_fibonacci : " << iterative_fibonacci(value) << endl;
	}
	return 0;
}
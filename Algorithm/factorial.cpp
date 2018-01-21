#include <iostream>

using namespace std;

int iterative_factorial(int value)
{
	int result = 1;
	for (int i = value; i > 0; i--)
		result *= i;
	return result;
}

int recursive_factorial(int value)
{
	int result = 1;
	if (value <= 1)
		result=1;
	else
		result = value*recursive_factorial(value - 1);
	return result;
}

int main()
{
	int value;
	while (true)
	{
		cout << "value : ";
		cin >> value;
		cout << "recursive : "<<recursive_factorial(value) << endl;
		cout << "iterative : " << iterative_factorial(value) << endl;
	}

	return 0;
}
#include <iostream>

using namespace std;

void hanoi_tower(int num, char tower1, char tower2, char tower3)
{
	if (num == 1)
	{
		cout << num << " : " << tower1 << " -> " << tower3 << endl;
	}
	else
	{
		hanoi_tower(num - 1, tower1, tower3, tower2);
		cout << num << " : " << tower1 << " -> " << tower3 << endl;
		hanoi_tower(num - 1, tower2, tower1, tower3);
	}
}

int main()
{
	char a = 'a';
	char b = 'b';
	char c = 'c';
	int num;

	cout << "num : ";
	cin >> num;
	hanoi_tower(num, a, b, c);

	return 0;
}
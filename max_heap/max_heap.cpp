#include "max_heap.h"

Max_heap::Max_heap(int _max_size)
{
	max_size = _max_size;
	current_size = 0;
	arr = new int[_max_size];
}

Max_heap::~Max_heap()
{
	delete[] arr;
}

void Max_heap::Insert(int value)
{
	arr[++current_size] = value;
	int next;
	int temp;
	int current = current_size;

	while (current != 1)
	{
		next = current / 2;
		if (arr[current] > arr[next])
		{
			temp = arr[current];
			arr[current] = arr[next];
			arr[next] = temp;
			current = next;
		}
		else
			break;
	}
}

int Max_heap::Delete()
{
	int value = arr[1];
	int current = 1;
	int left_next;
	int right_next;
	int temp;
	
	arr[current] = arr[current_size];
	
	while (current*2+1<=current_size)
	{
		left_next = current * 2;
		right_next = current * 2 + 1;

		if (arr[left_next] < arr[right_next])
		{
			if (arr[current] < arr[right_next])
			{
				temp = arr[current];
				arr[current] = arr[right_next];
				arr[right_next] = temp;
				current = right_next;
			}
			else
				break;
		}
		else
		{
			if (arr[current]<arr[left_next])
			{
				temp = arr[current];
				arr[current] = arr[left_next];
				arr[left_next] = temp;
				current = left_next;
			}
			else
				break;
		}
	}

	current_size--;
	return value;
}

void Max_heap::Display()
{
	for (int i = 1; i <= current_size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
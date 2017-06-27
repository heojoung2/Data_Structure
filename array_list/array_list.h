#include <iostream>

using namespace std;

template <typename T>
class Array_list {
private:
	int max_size;
	int length;
	T *arr;

public:
	Array_list(int _max_size)
	{
		max_size = _max_size;
		length = 0;
		Make_array();
	}

	void Make_array();
	void Display();
	int Get_length();
	bool Is_full();

	bool Add(int index, T value);
	bool Add_first(T value);
	bool Add_last(T value);
	
	bool Delete(int index);
	bool Delete_last();

	int Search(int index);

	void Clear_array();
	void Delete_array();
};

template <typename T>
void Array_list<T>::Make_array()
{
	arr = new T[max_size];
}

template <typename T>
void Array_list<T>::Display()
{
	if (length>0)
	{
		for (int i = 0; i < length; i++)
			cout << i << " : " << arr[i] << endl;
	}
	else
	{
		cout << "빈 리스트입니다" << endl;
	}
	cout << endl;
}

template <typename T>
int Array_list<T>::Get_length()
{
	return length;
}

template <typename T>
bool Array_list<T>::Is_full()
{
	if (length >= max_size)
		return true;
	return false;
}

template <typename T>
bool Array_list<T>::Add(int index, T value)
{
	if (0 <= index && index <= length && !Is_full())
	{
		int i;
		for (i = length; i > index; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[i] = value;
		length++;
		return true;
	}
	else
	{
		printf("%d : 추가 인덱스 오류\n", index);
		return false;
	}
}

template <typename T>
bool Array_list<T>::Add_first(T value)
{
	if (Add(0, value))
		return true;
	else
		return false;
}

template <typename T>
bool Array_list<T>::Add_last(T value)
{
	if (Add(length, value))
		return true;
	else
		return false;
}

template <typename T>
bool Array_list<T>::Delete(int index)
{
	if (0 <= index && index<length)
	{
		for (int i = index; i < length - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		length--;
		return true;
	}
	else
	{
		printf("%d : 삭제 인덱스 오류\n", index);
		return false;
	}
}

template <typename T>
bool Array_list<T>::Delete_last()
{
	if (Delete(length - 1))
		return true;
	else
		return false;
}

template <typename T>
int Array_list<T>::Search(int index)
{
	if (0 <= index && index <length)
	{
		return arr[index];
	}
	else
	{
		printf("%d : 찾기 인덱스 오류\n", index);
		return NULL;
	}
}

template <typename T>
void Array_list<T>::Clear_array()
{
	length = 0;
}

template <typename T>
void Array_list<T>::Delete_array()
{
	delete[] arr;
}
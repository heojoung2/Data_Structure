#include "graph_array.h"

Graph::Graph(int _size)
	:size(_size), direct(false)
{
	node = new int[size];
	memset(node, 0, sizeof(int)*_size);

	arr = new int*[size];
	for (int i = 0; i < _size; i++)
	{
		arr[i] = new int[size];
		memset(arr[i], 0, sizeof(int)*_size);
	}
}

void Graph::Make_graph()
{
	direct = false;
}

void Graph::Make_directed_graph()
{
	direct = true;
}

void Graph::Add_node(int vertex)
{
	if (node[vertex] == 1)
	{
		cout << "error exist vertex" << endl;
		exit(1);
	}
	node[vertex] = 1;
}

void Graph::Add_edge(int vertex1, int vertex2)
{
	if (!(node[vertex1] == 1 && node[vertex2] == 1))
	{
		cout << "error no node" << endl;
		exit(1);
	}

	arr[vertex1][vertex2] = 1;
	if (direct == false)
		arr[vertex2][vertex1] = 1;
}

void Graph::Add_edge(int vertex1, int vertex2, int weight)
{
	if (!(node[vertex1] == 1 && node[vertex2] == 1))
	{
		cout << "error no node" << endl;
		exit(1);
	}

	arr[vertex1][vertex2] = weight;
	if(direct==false)
		arr[vertex2][vertex1] = weight;
}

void Graph::Delete_node(int vertex)
{
	if (node[vertex] == 0)
	{
		cout << "error not existed node" << endl;
		exit(1);
	}

	for (int i = 0; i < size; i++)
	{
		if (arr[i][vertex] != 0)
		{
			cout << "error existed edge" << endl;
			exit(1);
		}
	}

	node[vertex] = 0;
}

void Graph::Delete_edge(int vertex1, int vertex2)
{
	if (!(node[vertex1] == 1 && node[vertex2] == 1))
	{
		cout << "error no node" << endl;
		exit(1);
	}

	if (arr[vertex1][vertex2] == 0)
	{
		cout << "error no edge" << endl;
		exit(1);
	}

	arr[vertex1][vertex2] = 0;

	if (direct == false)
		arr[vertex2][vertex1] = 0;
}

void Graph::Initial()
{
	for (int i = 0; i < size; i++)
	{
		node[i] = 0;
		for (int j = 0; j < size; j++)
			arr[i][j] = 0;
	}
}

void Graph::Display()
{
	cout << "  ";
	for (int i = 0; i < size; i++)
		cout << i << " ";
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i << " ";
		for (int j = 0; j < size; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}

Graph::~Graph()
{
	delete[] node;

	for (int i = 0; i < size; i++)
		delete[] arr[i];
	delete[] arr;
}

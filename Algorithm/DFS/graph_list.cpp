#include "graph_list.h"

Node::Node()
	:link(NULL), vertex(-1), weight(-1)
{}

Node::Node(int _vertex)
	: link(NULL), vertex(_vertex), weight(-1)
{}

Node::Node(int _vertex, int _weight)
	: link(NULL), vertex(_vertex), weight(_weight)
{}

void Node::Set_link(Node* _link)
{
	link = _link;
}

Node* Node::Get_link()
{
	return link;
}

void Node::Set_vertex(int _vertex)
{
	vertex = _vertex;
}

int Node::Get_vertex()
{
	return vertex;
}

void Node::Set_weight(int _weight)
{
	weight = _weight;
}

int Node::Get_weight()
{
	return weight;
}

Graph::Graph(int _size)
	:size(_size), direct(false)
{
	node = new int[size];
	memset(node, 0, sizeof(int)*size);

	arr = new Node[size];
	for (int i = 0; i < size; i++)
	{
		arr[i].Set_link(NULL);
		arr[i].Set_vertex(i);
		arr[i].Set_weight(-1);
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
		cout << "error existed vertex" << endl;
		exit(1);
	}
	node[vertex] = 1;
}

void Graph::Add_edge(int vertex1, int vertex2)
{
	Node* node;
	Node *add_node = new Node;
	add_node->Set_vertex(vertex2);

	node = arr[vertex1].Get_link();

	if (node == NULL)
		arr[vertex1].Set_link(add_node);
	else
	{
		while (node->Get_link() != NULL)
		{
			node = node->Get_link();
		}
		node->Set_link(add_node);
	}

	if (direct == false)
	{
		Node* node;
		Node *add_node = new Node;
		add_node->Set_vertex(vertex1);

		node = arr[vertex2].Get_link();

		if (node == NULL)
			arr[vertex2].Set_link(add_node);
		else
		{
			while (node->Get_link() != NULL)
			{
				node = node->Get_link();
			}
			node->Set_link(add_node);
		}
	}
}

void Graph::Add_edge(int vertex1, int vertex2, int weight)
{
	Node* node;
	Node *add_node = new Node;
	add_node->Set_vertex(vertex2);
	add_node->Set_weight(weight);

	node = arr[vertex1].Get_link();

	if (node == NULL)
		arr[vertex1].Set_link(add_node);
	else
	{
		while (node->Get_link() != NULL)
		{
			node = node->Get_link();
		}
		node->Set_link(add_node);
	}

	if (direct == false)
	{
		Node* node;
		Node *add_node = new Node;
		add_node->Set_vertex(vertex1);
		add_node->Set_weight(weight);

		node = arr[vertex2].Get_link();

		if (node == NULL)
			arr[vertex2].Set_link(add_node);
		else
		{
			while (node->Get_link() != NULL)
			{
				node = node->Get_link();
			}
			node->Set_link(add_node);
		}
	}
}

void Graph::Delete_node(int vertex)
{
	if (node[vertex] == 0)
	{
		cout << "error not existed node" << endl;
		exit(1);
	}

	if (arr[vertex].Get_link() != NULL)
	{
		cout << "error existed edge" << endl;
		exit(1);
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

	Node *node = arr[vertex1].Get_link();
	Node *delete_node = node->Get_link();

	if (node->Get_vertex()==vertex2)
	{
		arr[vertex1].Set_link(node->Get_link());
	}
	else
	{
		while (delete_node->Get_vertex() != vertex2)
		{
			node = delete_node;
			delete_node = delete_node->Get_link();
		}
		node->Set_link(delete_node->Get_link());
	}

	if (direct == false)
	{
		Node *node = arr[vertex2].Get_link();
		Node *delete_node = node->Get_link();

		if (node->Get_vertex() == vertex1)
		{
			arr[vertex2].Set_link(node->Get_link());
		}
		else
		{
			while (delete_node->Get_vertex() != vertex1)
			{
				node = delete_node;
				delete_node = delete_node->Get_link();
			}
			node->Set_link(delete_node->Get_link());
		}
	}
}

void Graph::Initial()
{
	for (int i = 0; i < size; i++)
	{
		node[i] = 0;
		arr[i].Set_link(NULL);
		arr[i].Set_weight(-1);
	}
}

void Graph::Display()
{
	for (int i = 0; i < size; i++)
	{
		if (node[i] != 0)
		{
			cout << i << " : ";
			Node *node;
			node = arr[i].Get_link();
			while (node != NULL)
			{
				cout << "vertex(" << node->Get_vertex() << ") weight(" << node->Get_weight() << ") ";
				node = node->Get_link();
			}
			cout << endl;
		}
	}
}

void Graph::DFS()
{
	cout << "DFS : ";
	int *flag_node = new int[size];
	memset(flag_node,0,sizeof(int)*size);

	stack<Node *> stack;
	int i;
	for (i = 0; i < size; i++)
	{
		if (node[i] == 1)
		{
			flag_node[i] = 1;
			stack.push(&arr[i]);
			break;
		}
	}

	Node *node;
	while (!stack.empty())
	{
		node = &arr[stack.top()->Get_vertex()];
		cout << node->Get_vertex()<<" ";
		stack.pop();
		
		while (node->Get_link() != NULL)
		{
			node = node->Get_link();
			if (flag_node[node->Get_vertex()] == 0)
			{
				stack.push(node);
				flag_node[node->Get_vertex()] = 1;
			}
		}
	}
	cout << endl;
	delete[] flag_node;
}

Graph::~Graph()
{
	delete[] node;
	delete[] arr;
}
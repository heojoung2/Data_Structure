#include "binary_search_tree.h"
#include <queue>

Node::Node()
	:left_node(NULL), right_node(NULL)
{}

Node::Node(int _data)
	: data(_data), left_node(NULL), right_node(NULL)
{}

int Node::Get_data()
{
	return data;
}

void Node::Set_data(int _data)
{
	data = _data;
}

Node* Node::Get_left_node()
{
	return left_node;
}

Node* Node::Get_right_node()
{
	return right_node;
}

void Node::Set_left_node(Node *_node)
{
	left_node = _node;
}

void Node::Set_right_node(Node *_node)
{
	right_node = _node;
}


Tree::Tree(Node *_node)
{
	root_node = _node;
}

Node Tree::Search(int _data)
{
	Node *current_node = root_node;
	while (current_node != NULL)
	{
		if (current_node->Get_data() < _data)
		{
			current_node = current_node->Get_right_node();
		}
		else if (current_node->Get_data() > _data)
		{
			current_node = current_node->Get_left_node();
		}
		else
			return *current_node;
	}
	cout << "Search error" << endl;
	exit(1);
}

void Tree::Insert(Node *_node)
{
	Node *current_node = root_node;
	Node *insert_node = NULL;
	bool right_flag;

	while (current_node!=NULL)
	{
		right_flag = false;
		if (current_node->Get_data() < _node->Get_data())
		{
			insert_node = current_node;
			current_node = current_node->Get_right_node();
			right_flag = true;
		}
		else if (current_node->Get_data() > _node->Get_data())
		{
			insert_node = current_node;
			current_node = current_node->Get_left_node();
		}
		else
		{
			cout << "Insert error" << endl;
			exit(1);
		}
	}
	if (right_flag == true)
		insert_node->Set_right_node(_node);
	else
		insert_node->Set_left_node(_node);
}

void Tree::Delete(int _data)
{
	Node *current_node = root_node;
	Node *parent_node = NULL;
	bool left_flag = false;
	
	while (current_node != NULL)
	{
		left_flag = false;
		if (current_node->Get_data() < _data)
		{
			parent_node = current_node;
			current_node = current_node->Get_right_node();
		}
		else if (current_node->Get_data() > _data)
		{
			left_flag = true;
			parent_node = current_node;
			current_node = current_node->Get_left_node();
		}
		else
		{
			if (current_node->Get_left_node() == NULL && current_node->Get_right_node() == NULL)
			{
				if(left_flag == true)
					parent_node->Set_left_node(NULL);
				else
					parent_node->Set_right_node(NULL);
			}
			else if (current_node->Get_left_node() == NULL &&current_node->Get_right_node() != NULL)
			{
				if (left_flag == true)
					parent_node->Set_left_node(current_node->Get_right_node());
				else
					parent_node->Set_right_node(current_node->Get_right_node());
			}
			else if (current_node->Get_left_node() != NULL &&current_node->Get_right_node() == NULL)
			{
				if (left_flag == true)
					parent_node->Set_left_node(current_node->Get_left_node());
				else
					parent_node->Set_right_node(current_node->Get_left_node());
			}
			else
			{
				Node *delete_node = current_node;
				current_node = current_node->Get_left_node();

				while (true)
				{
					parent_node = current_node;
					current_node = current_node->Get_right_node();
					if (current_node->Get_right_node() == NULL)
						break;
				}
				delete_node->Set_data(current_node->Get_data());
				parent_node->Set_right_node(current_node->Get_left_node());
			}

			return ;
		}
	}
	cout << "Delete error" << endl;
}

void Tree::Levelorder(Node *node)
{
	queue<Node*> queue;
	queue.push(node);
	Node* data;

	while (!queue.empty())
	{
		data = queue.front();
		cout << data->Get_data() << " ";
		queue.pop();

		if (data->Get_left_node() != NULL)
			queue.push(data->Get_left_node());
		if (data->Get_right_node() != NULL)
			queue.push(data->Get_right_node());
	}
	cout << endl;
}
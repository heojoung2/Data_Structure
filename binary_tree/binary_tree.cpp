#include "binary_tree.h"

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

Tree::Tree(Node _node)
{
	root_node = _node;
}

void Tree::Insert_left(Node *parent_node, Node *child_node)
{

	if (parent_node->Get_left_node() == NULL)
		parent_node->Set_left_node(child_node);
	else
	{
		cout << "insert left node error" << endl;
		exit(1);
	}
}

void Tree::Insert_right(Node *parent_node, Node *child_node)
{
	if (parent_node->Get_right_node() == NULL)
		parent_node->Set_right_node(child_node);
	else
	{
		cout << "insert right node error" << endl;
		exit(1);
	}
}

void Tree::Preorder(Node *_node)
{
	if (_node != NULL)
	{
		cout << _node->Get_data() << " ";
		Preorder(_node->Get_left_node());
		Preorder(_node->Get_right_node());
	}
}

void Tree::Inorder(Node *_node)
{
	if (_node != NULL)
	{
		Inorder(_node->Get_left_node());
		cout << _node->Get_data() << " ";
		Inorder(_node->Get_right_node());
	}

}

void Tree::Postorder(Node *_node)
{
	if (_node != NULL)
	{
		Postorder(_node->Get_left_node());
		Postorder(_node->Get_right_node());
		cout << _node->Get_data() << " ";
	}
}

int Tree::Count_leaf_node(Node *_node)
{
	int result = 0;

	if (_node != NULL)
	{
		if (_node->Get_left_node() == NULL && _node->Get_right_node() == NULL)
			result = 1;
		else if (_node != NULL)
		{
			result += Count_leaf_node(_node->Get_left_node());
			result += Count_leaf_node(_node->Get_right_node());
		}
	}
	return result;
}

int Tree::Height(Node *_node)
{
	int result=0;
	
	if (_node != NULL)
	{
		if (_node->Get_left_node() == NULL && _node->Get_right_node() == NULL)
			result = 1;
		else
		{
			int left = Height(_node->Get_left_node());
			int right = Height(_node->Get_right_node());

			if (left >= right)
				result = 1 + left;
			else
				result = 1 + right;
		}
	}
	return result;
}

#ifndef _BINARY_TREE_
#define _BINARY_TREE_

#include<iostream>
#include<queue>
using namespace std;

class Node
{
private:
	int data;
	Node* left_node;
	Node* right_node;

public:
	Node();
	Node(int _data);
	int Get_data();
	Node* Get_left_node();
	Node* Get_right_node();
	void Set_left_node(Node *_node);
	void Set_right_node(Node *_node);
};


class Tree
{
private:
	Node root_node;

public:
	Tree(Node _node);
	void Insert_left(Node *parent_node, Node *child_node);
	void Insert_right(Node *parent_node, Node *child_node);
	void Preorder(Node *_node);
	void Inorder(Node *_node);
	void Postorder(Node *_node);
	void Levelorder(Node *_node);
	int Count_leaf_node(Node *_node);
	int Height(Node *_node);
};

#endif _BINARY_TREE_
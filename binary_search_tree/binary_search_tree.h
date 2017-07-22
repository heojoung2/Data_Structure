#ifndef _BINARY_SEARCH_TREE_
#define _BINARY_SEARCH_TREE_

#include<iostream>
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
	void Set_data(int _data);
	Node* Get_left_node();
	Node* Get_right_node();
	void Set_left_node(Node *_node);
	void Set_right_node(Node *_node);
};

class Tree
{
private:
	Node *root_node;
public:
	Tree(Node *_node);
	Node Search(int _data);
	void Insert(Node *_node);
	void Delete(int _data);
	void Levelorder(Node *node);
};

#endif _BINARY_SEARCH_TREE_
#ifndef _GRAPH_LIST_
#define _GRAPH_LIST_

#include<iostream>

using namespace std;

class Node
{
private:
	Node* link;
	int vertex;
	int weight;
public:
	Node();
	Node(int _vertex);
	Node(int _vertex, int _weight);
	void Set_link(Node* _link);
	Node* Get_link();
	void Set_vertex(int _vertex);
	int Get_vertex();
	void Set_weight(int _weight);
	int Get_weight();
};

class Graph
{
private:
	int size;
	int *node;
	bool direct;
	Node *arr;
public:
	Graph(int _size);
	void Make_graph();
	void Make_directed_graph();
	void Add_node(int vertex);
	void Add_edge(int vertex1, int vertex2);
	void Add_edge(int vertex1, int vertex2, int weight);
	void Delete_node(int vertex);
	void Delete_edge(int vertex1, int vertex2);
	void Initial();
	void Display();
	~Graph();
};

#endif _GRAPH_LIST_
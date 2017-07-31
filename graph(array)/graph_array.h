#ifndef _GRAPH_ARRAY_
#define _GRAPH_ARRAY_

#include<iostream>

using namespace std;

class Graph
{
private:
	int *node;
	int **arr;
	int size;
	bool direct;
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

#endif _GRAPH_ARRAY_
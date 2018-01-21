#include "graph_list.h"

int main()
{
	int size = 8;
	Graph graph(size);
	graph.Make_graph();
	graph.Add_node(0);
	graph.Add_node(1);
	graph.Add_node(2);
	graph.Add_node(3);
	graph.Add_node(4);
	graph.Add_node(5);
	graph.Add_node(6);
	graph.Add_node(7);
	graph.Add_edge(0, 1);
	graph.Add_edge(0, 2);
	graph.Add_edge(1, 3);
	graph.Add_edge(1, 4);
	graph.Add_edge(4, 5);
	graph.Add_edge(2, 5);
	graph.Add_edge(2, 6);
	graph.Add_edge(3, 7);

	graph.DFS();
	return 0;
}
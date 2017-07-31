#include "graph.h"

int main()
{
	int size = 5;
	Graph graph(size);

	graph.Make_graph();
	graph.Add_node(0);
	graph.Add_node(1);
	graph.Add_node(3);
	graph.Add_edge(0, 1);
	graph.Add_edge(1, 3);
	graph.Delete_edge(0, 1);
	graph.Delete_node(0);
	graph.Display();

	graph.Initial();
	graph.Make_directed_graph();
	graph.Add_node(1);
	graph.Add_node(2);
	graph.Add_node(4);
	graph.Add_edge(1, 2, 9);
	graph.Add_edge(4, 1, 8);
	graph.Delete_edge(4,1);
	graph.Delete_node(1);
	
	
	graph.Display();

	return 0;
}
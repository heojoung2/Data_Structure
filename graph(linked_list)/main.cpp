#include "graph_list.h"

int main()
{
	int size = 5;
	Graph graph(5);
	graph.Make_graph();
	graph.Add_node(2);
	graph.Add_node(3);
	graph.Add_node(4);
	graph.Add_node(0);
	graph.Add_edge(2, 4, 9);
	graph.Add_edge(2, 3, 8);
	graph.Add_edge(0, 4, 7);
	graph.Delete_edge(2, 4);
	graph.Delete_edge(2, 3);
	graph.Delete_node(2);
	graph.Display();
	graph.Initial();

	cout << endl;
	graph.Make_directed_graph();
	graph.Add_node(0);
	graph.Add_node(4);
	graph.Add_node(1);
	graph.Add_node(2);
	graph.Add_edge(0, 1);
	graph.Add_edge(4, 1);
	graph.Add_edge(1, 4);
	graph.Add_edge(1, 2);
	graph.Delete_edge(0, 1);
	graph.Delete_node(0);
	graph.Display();

	return 0;
}
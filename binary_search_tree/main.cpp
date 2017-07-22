#include "binary_search_tree.h"

int main()
{
	Node node1(30);
	Tree tree(&node1);

	Node node2(20);
	tree.Insert(&node2);

	Node node3(40);
	tree.Insert(&node3);
	
	Node node4(10);
	tree.Insert(&node4);
	
	Node node5(6);
	tree.Insert(&node5);
	
	Node node6(14);
	tree.Insert(&node6);
	
	Node node7(24);
	tree.Insert(&node7);
	
	Node node8(22);
	tree.Insert(&node8);

	tree.Levelorder(&node1);

	tree.Delete(30);
	tree.Levelorder(&node1);

	return 0;
}
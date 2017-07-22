#include "binary_tree.h"

int main()
{
	Node node1(1);
	Tree tree(node1);

	Node node2(2);
	tree.Insert_left(&node1, &node2);

	Node node3(3);
	tree.Insert_right(&node1, &node3);

	Node node4(4);
	tree.Insert_left(&node2, &node4);

	cout << "Preorder : ";
	tree.Preorder(&node1);
	cout << endl << "Inorder : ";
	tree.Inorder(&node1);
	cout << endl << "Postorder : ";
	tree.Postorder(&node1);
	cout << endl << "Levelorder : ";
	tree.Levelorder(&node1);
	cout << endl;

	cout << "left node : " << tree.Count_leaf_node(&node1) << endl;
	cout << "height : " << tree.Height(&node1) << endl;


	return 0;
}
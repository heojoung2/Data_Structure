#include "linked_list.h"

Linked_list::Linked_list()
{
	length = 0;
	head = new Node;
	head->left_link = head;
	head->right_link = head;
}

int Linked_list::Get_length()
{
	return length;
}

Node *Linked_list::Get_head()
{
	return head;
}

void Linked_list::Display()
{
	Node *node = head;
	for (int i = 0; i < length; i++)
	{
		node = node->right_link;
		cout << node->coefficient<<"x^"<< node->degree;
		if (i!=length-1)
			cout << " + ";
	}
	if (length == 0)
	{
		cout << "비어있습니다" << endl;
	}
	cout << endl;
}

bool Linked_list::Add(float coefficient, int degree)
{
	Node *new_node = new Node;
	new_node->coefficient = coefficient;
	new_node->degree = degree;


	Node *previous_node = head;
	for (int i = 0; i < length; i++)
	{
		previous_node = previous_node->right_link;
		if (previous_node->degree==new_node->degree)
		{
			cout << new_node->degree << " : 추가 중복 에러" << endl;
			return false;
		}
		else if (previous_node->degree < new_node->degree)
		{
			previous_node = previous_node->left_link;
			break;
		}
	}

	new_node->right_link = previous_node->right_link;
	new_node->left_link = previous_node;
	previous_node->right_link = new_node;
	new_node->right_link->left_link = new_node;

	length++;

	return true;

}

bool Linked_list::Delete(int index)
{
	if (0 <= index && index < length)
	{
		Node *node = head;
		Node *delete_node = head;

		for (int i = 0; i < index; i++)
		{
			node = node->right_link;
			delete_node = delete_node->right_link;
		}
		delete_node = delete_node->right_link;

		node->right_link = delete_node->right_link;
		delete_node->right_link->left_link = node;
		length--;

		delete delete_node;
		return true;
	}
	else
	{
		cout << index << " : 삭제 인덱스 오류\n" << endl;
		return false;
	}
}


void Linked_list::Free()
{
	free(head);
}

Linked_list Plus(Linked_list polynomial1, Linked_list polynomial2)
{
	Linked_list result;

	Node *node1 = NULL;
	Node *node2 = NULL;

	node1 = polynomial1.Get_head()->right_link;
	node2 = polynomial2.Get_head()->right_link;

	int length1 = polynomial1.Get_length();
	int length2 = polynomial2.Get_length();

	while (!(length1 == 0 && length2 == 0))
	{
		if (length1 == 0)
		{
			while (length2 != 0)
			{
				result.Add(node2->coefficient, node2->degree);
				node2 = node2->right_link;
				length2--;
			}
		}
		else if (length2 == 0)
		{
			while (length1 != 0)
			{
				result.Add(node1->coefficient, node1->degree);
				node1 = node1->right_link;
				length1--;
			}
		}
		else if (node1->degree == node2->degree)
		{
			result.Add(node1->coefficient + node2->coefficient, node1->degree);
			node1 = node1->right_link;
			node2 = node2->right_link;
			length1--;
			length2--;
		}
		else if (node1->degree > node2->degree)
		{
			result.Add(node1->coefficient, node1->degree);
			node1 = node1->right_link;
			length1--;
		}
		else if (node1->degree < node2->degree)
		{
			result.Add(node2->coefficient, node2->degree);
			node2 = node2->right_link;
			length2--;
		}
	}
	return result;
};

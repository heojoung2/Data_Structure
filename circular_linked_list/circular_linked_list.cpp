#include "circular_linked_list.h"

Linked_list::Linked_list()
{
	length = 0;
	head = new Node;
	head->link = NULL;
}

int Linked_list::Get_length()
{
	return length;
}

void Linked_list::Display()
{
	Node *node = head;
	for (int i = 0; i < length; i++)
	{
		node = node->link;
		cout << node->data << endl;
	}
	if (length==0)
	{
		cout << "����ֽ��ϴ�" << endl;
	}
	cout << endl;
}

bool Linked_list::Add(int index, int data)
{
	Node *new_node = new Node;
	new_node->data = data;
	new_node->link = NULL;

	if (0 <= index && index <= length)
	{
		if (length==0)	//ó�� ��带 �����ϴ� ���
		{
			head->link = new_node;
			new_node->link = new_node;
		}
		else if (index==0)		//ù��°�� ��带 ������ ���
		{
			new_node->link = head->link;
			head->link = new_node;

			Node *node = head;
			for (int i = 0; i <= length; i++)
			{
				node = node->link;
			}
			node->link = new_node;
		}
		else
		{
			Node *previous_node = head;
			for (int i = 0; i < index; i++)
			{
				previous_node = previous_node->link;
			}
			new_node->link = previous_node->link;
			previous_node->link = new_node;
		}
		length++;

		return true;
	}
	else
	{
		cout << index << ": �߰� �ε��� ����\n" << endl;
		return false;
	}
}

bool Linked_list::Delete(int index)
{
	if (0 <= index && index < length)
	{
		if (index==0)		//ù��° ����� ��
		{
			if (length==1)	//��尡 �ϳ��� ��
			{
				Node *delete_node = head->link;
				head->link = NULL;
				delete delete_node;
			}
			else
			{
				Node *node = head;
				Node *delete_node = head->link;

				for (int i = 0; i < length; i++)
				{
					node = node->link;
				}
				head->link = delete_node->link;
				node->link = delete_node->link;

				delete delete_node;
			}
		}
		else
		{
			Node *node = head;
			Node *delete_node = head;

			for (int i = 0; i < index; i++)
			{
				node = node->link;
				delete_node = delete_node->link;
			}
			delete_node = delete_node->link;
			node->link = delete_node->link;

			delete delete_node;
		}
		length--;
		return true;
	}
	else
	{
		cout << index << " : ���� �ε��� ����\n" << endl;
		return false;
	}
}

int Linked_list::Search(int index)
{
	if (0 <= index && index < length)
	{
		Node *node = head;
		for (int i = 0; i <= index; i++)
		{
			node = node->link;
		}
		return node->data;
	}
	else
	{
		cout << index << " : ã�� �ε��� ����\n" << endl;
		return NULL;
	}
}

void Linked_list::Free()
{
	free(head);
}
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "CIP.h"

using namespace std;



void LinkedList:: insert(int data)
{
	Node* newNode = new Node(data);

	if (this->head == nullptr)
	{
		this->head = newNode;
	}
	else
	{
		this->tail->next = newNode;
	}
	this->tail = newNode;
}

void LinkedList:: printll(Node* head)
	{
		while (head != nullptr)
		{
			cout << head->data << " ";
			head = head->next;
		}
	}

void InitializeList(LinkedList& lList)
{
	lList.insert(3);
	lList.insert(4);
	lList.insert(5);
	lList.insert(5);
	lList.insert(4);
	lList.insert(2);
	lList.insert(2);
	lList.insert(4);
	lList.insert(4);
	lList.insert(4);
	lList.insert(8);
	lList.insert(4);
	lList.insert(3);
	lList.insert(3);

	cout << "Initialize list is:"<<"\n";
	lList.printll(lList.head);
	cout << "\n";
}

Node* removeDup(Node* head)
{
	Node* current = head;
	Node* next = nullptr;
	Node* prev = nullptr;
	while (current != nullptr)
	{
		prev = current;
		next = current->next;
		while (next != nullptr)
		{
			if (next->data != current->data)
			{
				prev = next;
			}
			else
			{
				prev->next = next->next;
			}
			next = next->next;

		}
		current = current->next;

	}
	return head;
}
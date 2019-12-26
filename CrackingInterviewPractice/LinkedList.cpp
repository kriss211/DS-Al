#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
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

int length(Node* head)
{
	Node* cursor = head;
	int count = 0;
	while (cursor != nullptr)
	{
		count++;
		cursor = cursor->next;
	}
	return count;
}

int convertToNum(Node* head, int lenList)
{
	int i = 0;
	int num = 0;
	while (i < lenList)
	{
		num += head->data * pow(10, i);
		head = head->next;
		i++;
	}
	return num;
}

Node* reverseList(Node* head)
{
	if (head->next == nullptr || head == nullptr)
	{
		return head;
	}
	Node* newhead = reverseList(head->next);
	head->next->next = head;
	head->next = nullptr;
	return newhead;
}

Node* copyList(Node* oldHead, Node* newHead)
{
	while (oldHead != nullptr)
	{

		Node* newNode = new Node(oldHead->data);
		Node* cursor = newHead;
		if (newHead == nullptr)
		{
			newHead = newNode;
		}
		else
		{
			while (cursor->next != nullptr)
			{
				cursor = cursor->next;
			}
			cursor->next = newNode;
		}
		oldHead = oldHead->next;
	}
	return newHead;
}

/*Create a new node and insert at head*/
Node* reverseAndClone(Node* head)
{
	Node* newHead = nullptr;
	while (head != nullptr)
	{
		Node* newNode = new Node(head->data);
		newNode->next = newHead;
		newHead = newNode;
		head = head->next;
	}
	return newHead;
}

void InitializeList(LinkedList& lList)
{
	lList.insert(3);
	lList.insert(4);
	lList.insert(5);
	//lList.insert(5);
	lList.insert(4);
	lList.insert(5);
	//lList.insert(2);
	//lList.insert(4);
	//lList.insert(4);
	//lList.insert(4);
	//lList.insert(8);
	//lList.insert(4);
	//lList.insert(3);
	//lList.insert(3);

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

/*iterative: use 2 pointer p1 and p2 which p1 will run fordware k step to p2
when p1 reach to the end node p2 will be the node that kth to end
time O(n) and space O(1)*/
Node* returnKth(Node* head, int k)
{
	Node* leader = head;
	Node* follower = head;
	/*move leader k step fordware follower*/
	for (int i = 0; i < k; i++)
	{
		leader = leader->next;
	}
	while (leader != nullptr)
	{
		leader = leader->next;
		follower = follower->next;
	}
	//cout << "Data at pos " << k << " to end is:" << follower->data<<"\n";
	return follower;
}

/*recursive: traverse to the end then use and counter to count from 0 to k
time O(1) and space O(n)*/
//Node* returnKth(Node* head, int k)
//{
//	int i = 0;
//	return returnKth(head->next, k, i);
//}
//
//Node* returnKth(Node* head, int k, int &i) //overload of returnKth
//{
//	if (head->next == nullptr)
//	{
//		return nullptr;
//	}
//	Node* tempNode = returnKth(head->next, k, i);
//	i = i + 1;
//	if (i == k)
//	{
//		return head;
//	}
//	return tempNode;
//}

Node* deleteMid(Node* head, int data)
{
	Node* cursor = head;
	Node* tail = head;
	Node* prev = nullptr;
	while (data == head->data)
	{
		cout << "Please enter the middle node:";
		cin >> data;
	}
	while (tail->next != nullptr)
	{
		tail = tail->next;
	}
	while(tail->data == data)
	{
		
		cout << "Please enter the middle node:";
		cin >> data;
		
	}
	while(cursor->next != nullptr)
	{
		prev = cursor;
		cursor = cursor->next;
		if (cursor->data == data)
		{
			prev->next = cursor->next;
		}
	}

	return head;
		

		
	
	 

}

/*first approach: use first node to create a new list, every old node->data < partition
insert that node to head else insert at tail*/
Node* partition(Node* head, int partition)
{
	Node* cursor = head->next;
	Node* preCursor = head;
	while (cursor != nullptr)
	{
		if (cursor->data < partition)
		{
			preCursor->next = cursor->next;
			cursor->next = head;
			head = cursor;
			cursor = preCursor->next;
		}
		else
		{
			preCursor = cursor;
			cursor = cursor->next;
		}
	}
	return head;

}

/*second approach: create 2 new list, 1 for smaller value, other for bigger;when
reach to end list merge 2 list together*/
//Node* partition(Node* head, int partition)
//{
//	Node* smallerHead = nullptr;
//	Node* smallerTail = nullptr;
//	Node* biggerHead = nullptr;
//	Node* biggerTail = nullptr;
//	Node* retainNode = nullptr;
//
//	while (head != nullptr)
//	{
//	retainNode = head->next;
//	if (head->data < partition)
//	{
//
//	head->next = smallerHead;
//	smallerHead = head;
//	}
//	else
//	{
//	head->next = biggerHead;
//	biggerHead = head;
//	}
//	head = retainNode;
//	}
//	smallerTail = smallerHead;
//	biggerTail = biggerHead;
//
//	while (smallerTail != nullptr && smallerTail->next != nullptr)
//	{
//	smallerTail = smallerTail->next;
//	}
//
//	while (biggerTail != nullptr && biggerTail->next != nullptr)
//	{
//	biggerTail = biggerTail->next;
//	}
//	biggerTail->next = nullptr;
//	if (smallerTail == nullptr) return biggerHead;
//	else smallerTail->next = biggerHead;
//
//	return smallerHead;
//
//}

void sumLists(Node* numList1, Node* numList2)
{
	int lenList1 = length(numList1);
	int lenList2 = length(numList2);

	int num1 = convertToNum(numList1, lenList1);
	int num2 = convertToNum(numList2, lenList2);

	int i1 = 0;
	int i2 = 0;
	long sum = 0;
	int data = 0;
	Node* newhead = nullptr;

	sum = num1 + num2;

	while (sum != 0)
	{
		data = sum % 10;
		sum = sum / 10;
		if (newhead == nullptr)
		{
			newhead = new Node(data);
		}
		else
		{
			Node *cursor = newhead;
			Node *newNode = new Node(data);
			while (cursor->next != nullptr)
			{
				cursor = cursor->next;
			}
			cursor->next = newNode;
		}
	}
	while (newhead != nullptr)
	{
		cout << newhead->data << " ";
		newhead = newhead->next;
	}
}

/*Solution 1: list 0 1 2 3 4
check 0 with 4 and 1 with 3 ....*/
//bool checkPalindrome(Node* head)
//{
//	 int len = length(head);
//	 int interateList = 1;
//	 int decreaseLoop = 1;
//
//	 while (len > len / 2)
//	 {
//		 Node* cursor = head;
//		 interateList = decreaseLoop;
//		 while (interateList < len)
//		 {
//			 cursor = cursor->next;
//			 interateList++;
//		 }
//		 if (head->data != cursor->data) return false;
//		 head = head->next;
//		 decreaseLoop++;
//		 len--;
//	 }
//	 return true;
//
//}

/*Solution 2: create a reverse list and check the first half original with reverse list*/
bool checkPalindrome(Node* head)
{
	int len = length(head);
	Node* reverseHead = nullptr;
	reverseHead = copyList(head, reverseHead);
	reverseHead = reverseList(reverseHead);

	for (int i = 0; i < len / 2; i++)
	{
		if (head->data != reverseHead->data)
		{
			return false;
		}
		head = head->next;
		reverseHead = reverseHead->next;
	}

	return true;
}

//intersectionResult intersection(Node* head1, Node* head2)
//{
//	intersectionResult result;
//	int len1 = length(head1);
//	int len2 = length(head2);
//	int sumlen = len1 + len2;
//	Node* cursor1 = head1;
//	Node* cursor2 = head2;
//	while (cursor1 != cursor2 && sumlen >= 0)
//	{
//		if (cursor1 != nullptr)
//		{
//			cursor1 = cursor1->next;
//		}
//		else
//		{
//			cursor1 = head2;
//		}
//		if (cursor2 != nullptr)
//		{
//			cursor2 = cursor2->next;
//		}
//		else
//		{
//			cursor2 = head1;
//		}
//		sumlen--;
//	}
//	if (sumlen >= 0)
//	{
//		result.isIntersection = true;
//		result.data = cursor1->data;
//	}
//	else
//	{
//		result.isIntersection = false;
//	}
//	return result;
//}

/*solution2: find lenght of 2 list; traverse the longer list when cut off number of node that equal to diff len between 2 node*/
intersectionResult intersection(Node* head1, Node* head2)
{
	intersectionResult result;
	int len1 = length(head1);
	int len2 = length(head2);

	Node* clonger = len1 > len2 ? head1 : head2;
	Node* cshorter = len1 > len2 ? head2 : head1;

	int difflen = abs(len1 - len2);

	while (difflen > 0)
	{
		clonger = clonger->next;
		difflen--;
	}

	while (clonger != cshorter && clonger != nullptr)
	{
		clonger = clonger->next;
		cshorter = cshorter->next;
	}
	

	if (clonger != nullptr)
	{
		result.isIntersection = true;
		result.data = clonger->data;
	}
	else
	{
		result.isIntersection = false;
	}
	return result;
}

/*Solution: head and collision node are both k node from begin of loop
So if move 1 slownode and faster (2 time faster) at same time we can find the collision point-> move slower to head and start
move 2 slower and faster at same speed they will meet again at  start loop*/
loopdectecResult loopDetection(Node* head)
{
	Node* slower = head;
	Node* faster = head;
	loopdectecResult Res;
	while (faster != nullptr && faster->next != nullptr)
	{
		if (faster == slower)
		{
			break;
		}
		slower = slower->next;
		faster = faster->next->next;
	}

	if (faster == nullptr || faster->next != nullptr)
	{
		Res.node = head;
		Res.isLoop = false;
	}

	slower = head;

	while (slower != faster)
	{
		slower = slower->next;
		faster = faster->next;
	}
	Res.node = faster;
	Res.isLoop = true;
	return Res;

}

Node* reverseUseStack(Node* head)
{
	if (head == nullptr) return head;
	Node* cursor = head;
	stack<Node*> S;
	while (cursor != nullptr)
	{
		S.push(cursor);
		cursor = cursor->next;
	}
	cursor = S.top();
	head = cursor;
	S.pop();
	while (!S.empty())
	{
		cursor->next = S.top();
		S.pop();
		cursor = cursor->next;
	}
	cursor->next = nullptr;
	return head;
}
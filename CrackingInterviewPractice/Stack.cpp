#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>
#include "CIP.h"


static bool checkPair(char c, char top)
{
	if (c == ')' && top == '(') return true;
	else if (c == '}' && top == '{') return true;
	else if (c == ']' && top == '[') return true;
	else return false;
	
}

bool balanceParenthesis(string s)
{
	stack<char> Stack;
	
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			Stack.push(s[i]);
		}
		else
		{
			if (s[i] == ')' || s[i] == '}' || s[i] == ']')
			{
				if (Stack.empty() || !checkPair(s[i], Stack.top()))
					return false;
				else
					Stack.pop();
			}
		}
	}
	if (Stack.empty()) return true;
	else return false;
}

/*check min: every node will has another property is min which store the smallest value 
from this node to the first node*/
selfStack::selfStack()
{
	this->head = nullptr;
}

bool selfStack::isEmpty()
{
	return head == nullptr;
	
}

selfStack::stackNode* selfStack::Peek()
{
	return head;
}

int selfStack::Min()
{
	return head->min;
}

void selfStack::Push(int data)
{
	selfStack::stackNode* newNode = new selfStack::stackNode(data);

	if (!isEmpty())
	{
		if (head->min < newNode->data)
		{
			newNode->min = head->min;
		}
	}
	newNode->next = head;
	head = newNode;
}

selfStack::stackNode* selfStack::Pop()
{
	selfStack::stackNode* temp = head;
	if (isEmpty())
	{
		printf("Stack is empty");
		return nullptr;
	}
	head = head->next;
	delete temp;
}

void checkMin()
{
	selfStack Stack;
	Stack.Push(2);
	cout << "Min is:" << Stack.Min() << '\n';
	Stack.Push(3);
	cout << "Min is:" << Stack.Min() << '\n';
	Stack.Push(1);
	cout << "Min is:" << Stack.Min() << '\n';
	Stack.Push(4);
	cout << "Min is:" << Stack.Min() << '\n';
	Stack.Push(0);
	cout << "Min is:" << Stack.Min() << '\n';
	Stack.Pop();
	cout << "Min is:" << Stack.Min() << '\n';
	Stack.Pop();
	cout << "Min is:" << Stack.Min() << '\n';
	Stack.Pop();
	cout << "Min is:" << Stack.Min() << '\n';
	Stack.Push(0);
	cout << "Min is:" << Stack.Min() << '\n';
	Stack.Pop();
	cout << "Min is:" << Stack.Min() << '\n';
}

/*Set of stack: create Set of stack as a big stack which contain stack*/

SetOfStack::handmadeStack::NodeStack::NodeStack(int data)
{
	this->data = data;
	this->next = nullptr;
}

SetOfStack::handmadeStack::handmadeStack()
{
	this->size = 0;
	this->nextStack = nullptr;
	this->headOfStack = nullptr;
}

SetOfStack::SetOfStack()
{
	this->capacity = 3;
	headOfSet = nullptr;

}

bool SetOfStack::isSetEmpty()
{
	return headOfSet == nullptr;
}

bool SetOfStack::isStackFull(handmadeStack* stackNo)
{
	return stackNo->size == this->capacity;
}

SetOfStack::handmadeStack* SetOfStack::PushToStack(handmadeStack* headSet, int data)
{

	handmadeStack::NodeStack* newNode = new handmadeStack::NodeStack(data);
	/*if Set empty create a new one*/
	if (isSetEmpty())
	{
		handmadeStack* newStack = new handmadeStack();
		headSet = newStack;
	}
	/*if current stack is full create a new one*/
	if (isStackFull(headSet))
	{
		handmadeStack* newStack = new handmadeStack();
		newStack->nextStack = headSet;
		headSet = newStack;
	}
	/*Add new node to stack(add at head in linkedlist) + increase size*/
	newNode->next = headSet->headOfStack;
	headSet->headOfStack = newNode;
	headSet->size++;
	return headSet;
}

SetOfStack::handmadeStack* SetOfStack::PopFromStack(handmadeStack* headSet)
{
	/*if stack is empty and set is empty return nullptr*/
	if (headSet->headOfStack == nullptr)
	{
		if (headSet->nextStack == nullptr) return nullptr;

		/*assign head of set to next stack*/
		else
		{
			handmadeStack* deleteStack = headSet;
			headSet = headSet->nextStack;
			delete deleteStack;
		}
	}
	handmadeStack::NodeStack* deleteNode = headSet->headOfStack;
	headSet->headOfStack = headSet->headOfStack->next;
	headSet->size--;
	delete deleteNode;
	/*After pop if this stack is empty assign head set to next stack*/
	if (headSet->headOfStack == nullptr)
	{
		headSet = headSet->nextStack;
	}
	return headSet;
}

int SetOfStack::TopOfStack(handmadeStack* headSet)
{
	if (headSet->headOfStack == nullptr)
	{
		cout << "Stack is empty";
		return -1;
	}

	return headSet->headOfStack->data;
}

SetOfStack::handmadeStack* SetOfStack::PopAt(handmadeStack* headSet, int index)
{
	if (index == headSet->size)
	{
		cout << "Position is out of range\n";
		return headSet;
	}
	int step = headSet->size - 1 - index;
	SetOfStack::handmadeStack::NodeStack* cursorStack = headSet->headOfStack;
	SetOfStack::handmadeStack::NodeStack* preCursorStack = nullptr;

	while (step > 0)
	{
		preCursorStack = cursorStack;
		cursorStack = cursorStack->next;
		step--;
	}
	if(preCursorStack != nullptr) preCursorStack->next = cursorStack->next;
	else headSet->headOfStack = cursorStack->next;
	headSet->size--;

	delete cursorStack;
	return headSet;
}

void checkSetOfStack()
{
	SetOfStack sos = SetOfStack();
	SetOfStack::handmadeStack stackNo = SetOfStack::handmadeStack();
	/*first stack*/
	sos.headOfSet = sos.PushToStack(sos.headOfSet,8);
	cout << "First stack push:" << sos.TopOfStack(sos.headOfSet) << "\n";
	cout << "Address of first stack: " << sos.headOfSet << "\n";
	sos.headOfSet = sos.PushToStack(sos.headOfSet, 7);
	cout << "First stack push:" << sos.TopOfStack(sos.headOfSet) << "\n";
	cout << "Address of first stack: " << sos.headOfSet << "\n";
	sos.headOfSet = sos.PushToStack(sos.headOfSet, 6);
	cout << "First stack push:" << sos.TopOfStack(sos.headOfSet) << "\n";
	cout << "Address of first stack: " << sos.headOfSet << "\n";
	/*Second stack*/
	sos.headOfSet = sos.PushToStack(sos.headOfSet, 5);
	cout << "Second stack push :" << sos.TopOfStack(sos.headOfSet) << "\n";
	cout << "Address of second stack: " << sos.headOfSet << "\n";
	sos.headOfSet = sos.PushToStack(sos.headOfSet, 4);
	cout << "Second stack push :" << sos.TopOfStack(sos.headOfSet) << "\n";
	cout << "Address of second stack: " << sos.headOfSet << "\n";
	sos.headOfSet = sos.PushToStack(sos.headOfSet, 3);
	cout << "Second stack push :" << sos.TopOfStack(sos.headOfSet) << "\n";
	cout << "Address of second stack: " << sos.headOfSet << "\n";
	/*third*/
	sos.headOfSet = sos.PushToStack(sos.headOfSet, 2);
	cout << "Third stack push :" << sos.TopOfStack(sos.headOfSet) << "\n";
	cout << "Address of third stack: " << sos.headOfSet << "\n";
	sos.headOfSet = sos.PushToStack(sos.headOfSet, 1);
	cout << "Third stack push :" << sos.TopOfStack(sos.headOfSet) << "\n";
	cout << "Address of third stack: " << sos.headOfSet << "\n";
	sos.headOfSet = sos.PushToStack(sos.headOfSet, 0);
	cout << "Third stack push :" << sos.TopOfStack(sos.headOfSet) << "\n";
	cout << "Address of third stack: " << sos.headOfSet << "\n";

	sos.headOfSet = sos.PopAt(sos.headOfSet, 2);
	//cout << sos.TopOfStack(sos.headOfSet) << "\n";
	sos.headOfSet = sos.PopAt(sos.headOfSet, 0);
	cout << sos.TopOfStack(sos.headOfSet) << "\n";
	sos.headOfSet = sos.PopFromStack(sos.headOfSet);
	cout << sos.TopOfStack(sos.headOfSet) << "\n";
	sos.headOfSet = sos.PopFromStack(sos.headOfSet);
	cout << sos.TopOfStack(sos.headOfSet) << "\n";
	//sos.headOfSet = sos.PopFromStack(sos.headOfSet);
	//cout << sos.TopOfStack(sos.headOfSet) << "\n";	
	//sos.headOfSet = sos.PopFromStack(sos.headOfSet);
	//cout << sos.TopOfStack(sos.headOfSet) << "\n";
	//sos.headOfSet = sos.PopFromStack(sos.headOfSet);
	//cout << sos.TopOfStack(sos.headOfSet) << "\n";

}

/*Queue with 2 stack*/

myQueue::myQueue()
{
	oldestStack = stack<int>();
	newestStack = stack<int>();

}

void myQueue::transferStack()
{
	while (!newestStack.empty())
	{
		oldestStack.push(newestStack.top());
		newestStack.pop();
	}
}

void myQueue::Enqueue(int data)
{
	newestStack.push(data);
}

int myQueue::Dequeue()
{
	int ret = -1;
	if (oldestStack.empty()) transferStack();
	ret = oldestStack.top();
	oldestStack.pop();
	return ret;
}

void checkMyQueue()
{
	myQueue Queue;
	Queue.Enqueue(1);
	Queue.Enqueue(2);
	Queue.Enqueue(3);
	Queue.Enqueue(4);

	cout << "Dequeue: " << Queue.Dequeue() << "\n";
	cout << "Dequeue: " << Queue.Dequeue() << "\n";
	cout << "Dequeue: " << Queue.Dequeue() << "\n";

}

/*O(n^2) time and O(n) space: push the top ele from raw to sorted
, check the top of these 2:
if: raw.top > sorted > top => push it into sorted
else: */

stack<int> sortStack(stack<int> rawStack)
{
	int temp = 0;
	stack<int> sortedStack = stack<int>();
	if (sortedStack.empty())
	{
		sortedStack.push(rawStack.top());
		rawStack.pop();
	}
	while (!rawStack.empty())
	{
		if (rawStack.top() < sortedStack.top())
		{
			sortedStack.push(rawStack.top());
			rawStack.pop();
		}
		else
		{
			temp = rawStack.top();
			rawStack.pop();
			while (!sortedStack.empty() &&temp > sortedStack.top())
			{
				rawStack.push(sortedStack.top());
				sortedStack.pop();
			}
			sortedStack.push(temp);
		}
	}
	return sortedStack;
}
void checkSortStack()
{
	stack<int> testStack = stack<int>();
	testStack.push(2);
	testStack.push(6);
	testStack.push(1);
	testStack.push(7);
	testStack.push(3);
	testStack.push(8);
	testStack.push(5);
	testStack.push(9);
	testStack.push(4);
	testStack.push(10);
	testStack = sortStack(testStack);
	cout << "Stack after sorted: ";
	while (!testStack.empty())
	{
		cout << testStack.top() << " ";
		testStack.pop();
	}

}
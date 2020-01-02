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

void checkSetOfStack()
{
	SetOfStack sos = SetOfStack();
	SetOfStack::handmadeStack stackNo = SetOfStack::handmadeStack();
	/*first stack*/
	sos.headOfSet = sos.PushToStack(sos.headOfSet,5);
	cout << "First stack push 1st:" << sos.TopOfStack(sos.headOfSet) << "\n";
	cout << "Address of first stack: " << sos.headOfSet << "\n";
	sos.headOfSet = sos.PushToStack(sos.headOfSet, 6);
	cout << "First stack push 1st:" << sos.TopOfStack(sos.headOfSet) << "\n";
	cout << "Address of first stack: " << sos.headOfSet << "\n";
	/*Second stack*/
	sos.headOfSet = sos.PushToStack(sos.headOfSet, 4);
	cout << "Second stack push 2rd:" << sos.TopOfStack(sos.headOfSet) << "\n";
	cout << "Address of second stack: " << sos.headOfSet << "\n";
	sos.headOfSet = sos.PushToStack(sos.headOfSet, 3);
	cout << "Second stack push 2rd:" << sos.TopOfStack(sos.headOfSet) << "\n";
	cout << "Address of second stack: " << sos.headOfSet << "\n";

	sos.headOfSet = sos.PopFromStack(sos.headOfSet);
	cout << sos.TopOfStack(sos.headOfSet) << "\n";
	sos.headOfSet = sos.PopFromStack(sos.headOfSet);
	cout << sos.TopOfStack(sos.headOfSet) << "\n";
	sos.headOfSet = sos.PopFromStack(sos.headOfSet);
	cout << sos.TopOfStack(sos.headOfSet) << "\n";

}

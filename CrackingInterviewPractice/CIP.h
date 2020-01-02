#pragma once
#include <string>

using namespace std;

inline void newLine()
{
	cout << "\n";
}

/*Array and String*/
extern bool checkUnique(string);
extern bool checkPermutation(string, string);
string URLify(int);
bool checkPalindromePermutation(string);
bool OneAway(string, string);
string StringCompression(string);
void ZeroMatrix(void);
bool StringRotation(string, string);
bool isSubstring(string, string);



/*Linked List*/
class Node {
public:
	int data;
	Node* next;
	Node(int data)
	{
		this->data = data;
		this->next = nullptr;
	}
};

class LinkedList {
public:
	Node* head;
	Node* tail;

	LinkedList()
	{
		this->head = nullptr;
		this->tail = nullptr;
	}
	void insert(int);
	void printll(Node*);

};

class intersectionResult
{
public:
	int data;
	bool isIntersection;
};

class loopdectecResult
{
public:
	Node* node;
	bool isLoop;
};

void InitializeList(LinkedList&);
int length(Node*);
Node* removeDup(Node*);
Node* returnKth(Node*, int);
Node* deleteMid(Node*, int);
Node* partition(Node*, int);
void sumLists(Node*, Node*);
bool checkPalindrome(Node*);
intersectionResult intersection(Node*, Node*);
Node* reverseUseStack(Node*);

/*Stack*/
class selfStack
{
public:
	class stackNode
	{
	public: 
		int data;
		int min;
		stackNode* next;

		stackNode(int data)
		{
			this->min = data;
			this->data = data;
			this->next = nullptr;
		}
	};

	stackNode* head;
	selfStack()
	{
		this->head = nullptr;
	}

	bool isEmpty();
	stackNode* Peek();
	void Push(int);
	stackNode* Pop();
	int Min();
};

void checkMin();
bool balanceParenthesis(string);
void checkSetOfStack();



class SetOfStack
{
public:
	class handmadeStack
	{
	public:
		int size;
		handmadeStack* nextStack;
		class NodeStack {
		public:
			int data;
			NodeStack* next;

			NodeStack(int data)
			{
				this->data = data;
				this->next = nullptr;
			}

		};
		NodeStack* headOfStack;
		handmadeStack()
		{
			this->size = 0;
			this->nextStack = nullptr;
			this->headOfStack = nullptr;
		}

	};

	int capacity;
	handmadeStack* headOfSet;

	SetOfStack()
	{
		this->capacity = 2;
		headOfSet = nullptr;
	}

	bool isSetEmpty()
	{
		return headOfSet == nullptr;
	}

	bool isStackFull(handmadeStack* stackNo)
	{
		return stackNo->size == this->capacity;
	}

	handmadeStack* PushToStack(handmadeStack* headSet, int data)
	{
		handmadeStack::NodeStack* newNode = new handmadeStack::NodeStack(data);
		if (isSetEmpty())
		{
			handmadeStack* newStack = new handmadeStack();
			headSet = newStack;
		}
		if (isStackFull(headSet))
		{
			handmadeStack* newStack = new handmadeStack();
			newStack->nextStack = headSet;
			headSet = newStack;
		}
		newNode->next = headSet->headOfStack;
		headSet->headOfStack = newNode;
		headSet->size++;
		return headSet;
	}

	handmadeStack* PopFromStack(handmadeStack* headSet)
	{
		if (headSet->headOfStack == nullptr)
		{
			if (headSet->nextStack == nullptr) return nullptr;
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
		if (headSet->headOfStack == nullptr)
		{
			headSet = headSet->nextStack;
		}
		return headSet;
	}

	int TopOfStack(handmadeStack* headSet)
	{
		if (headSet->headOfStack == nullptr)
		{
			cout << "Stack is empty";
			return -1;
		}
		
		return headSet->headOfStack->data;
	}
};
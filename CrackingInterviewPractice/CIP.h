#pragma once
#include <string>
#include <stack>

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
	selfStack();
	
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

			NodeStack(int);

		};
		NodeStack* headOfStack;
		handmadeStack();
		
	};

	int capacity;
	handmadeStack* headOfSet;

	SetOfStack();
	bool isSetEmpty();
	bool isStackFull(handmadeStack*);
	handmadeStack* PushToStack(handmadeStack*, int);
	handmadeStack* PopFromStack(handmadeStack*);
	int TopOfStack(handmadeStack*);
	handmadeStack* PopAt(handmadeStack*, int);


};

class myQueue
{
public:
	stack<int> oldestStack, newestStack;
	myQueue();
	
	void transferStack();
	void Enqueue(int);
	int Dequeue();
};
void checkMyQueue();

stack<int> sortStack(stack<int>);
void checkSortStack();




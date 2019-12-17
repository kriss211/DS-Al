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

void InitializeList(LinkedList&);
int length(Node*);
Node* removeDup(Node*);
Node* returnKth(Node*, int);
Node* deleteMid(Node*, int);
Node* partition(Node*, int);
void sumLists(Node*, Node*);
bool checkPalindrome(Node*);

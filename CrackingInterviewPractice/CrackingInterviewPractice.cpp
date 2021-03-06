// CrackingInterviewPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "CIP.h"

using namespace std;

void ArrayandStrings(int);
void LinkedListFunction(int);
void Stack(int);



int main()
{
	int lessonChoice;
	int quesChoice;

    cout << "Welcome to workshop!\n";
	cout << "Choose your lesson:\n";
	cout << "	1. Array and Strings!\n";
	cout << "	2. Linked list!\n";
	cout << "	3. Stack!\n";


	cin >> lessonChoice;
	switch (lessonChoice)
	{
	case 1:  
		cout << "Choose your quesion:\n";
		cout << "	1. Is Unique!\n";
		cout << "	2. Check Permutation!\n";
		cout << "	3. URLify!\n";
		cout << "	4. Palindrome Permutation!\n";
		cout << "	5. One Away!\n";
		cout << "	6. String Compression!\n";
		cout << "	8. Zero Matrix!\n";
		cout << "	9. String Rotation!\n";

		cin >> quesChoice;
		ArrayandStrings(quesChoice);
		break;
	case 2:
		cout << "Choose your quesion:\n";
		cout << "	1. RemoveDups!\n";
		cout << "	2. Return Kth!\n";
		cout << "	3. Delete Mid Node!\n";
		cout << "	4. Partition!\n";
		cout << "	5. Sum list!\n";
		cout << "	6. Palindrome!\n";
		cout << "	7. Intersection!\n";
		cout << "	8. Reverse using stack!\n";

		cin >> quesChoice;
		LinkedListFunction(quesChoice);
		break;

	case 3:
		cout << "Choose your quesion:\n";
		cout << "	1. Balance Parenthesis!\n";
		cout << "	2. Min!\n";
		cout << "	3. Stack of plates!\n";
		cout << "	4. Queue with 2 stack!\n";
		cout << "	5. Sort Stack!\n";
		cout << "	6. Pet selter!\n";


		cin >> quesChoice;
		Stack(quesChoice);

	default:
		break;
	}

}

void ArrayandStrings(int quesChoice)
{
	string Sinput;
	string firstStr;
	string secondStr;
	int size;

	switch (quesChoice)
	{
	case 1:
		cout << "Please insert the string: ";
		cin >> Sinput;
		if (checkUnique(Sinput))
		{
			cout << "The string is unique";
		}
		else
		{
			cout << "The string is not unique";
		}
		break;

	case 2:
		cout << "Please insert the first string: ";
		cin >> firstStr;
		cout << "Please insert the second string: ";
		cin >> secondStr;

		if (checkPermutation(firstStr, secondStr))
		{
			cout << "These two string is Permutation!";
		}
		else
		{
			cout << "These two string is not Permutation!";
		}
		break;

	case 3:
		cout << "Please insert the size: ";
		cin >> size;
		cout << "New string is: " << URLify(size);
		break;

	case 4:
		cout << "Please insert the string: ";
		cin >> Sinput;
		cout << "Is Palindrome Permutation " << checkPalindromePermutation(Sinput);
		break;

	case 5:
		cout << "Please insert the first string: ";
		cin >> firstStr;
		cout << "Please insert the second string: ";
		cin >> secondStr;
		cout << "Result is: " << OneAway(firstStr, secondStr);
		break;

	case 6:
		cout << "Please insert the string: ";
		cin >> Sinput;
		cout << "New string is: " << StringCompression(Sinput);
		break;

	case 8:
		ZeroMatrix();
		break;

	case 9:
		cout << "Please insert the first string: ";
		cin >> firstStr;
		cout << "Please insert the second string: ";
		cin >> secondStr;
		cout << "Result is: " << StringRotation(firstStr, secondStr);
		StringRotation(firstStr, secondStr);
		break;
	}
}

void LinkedListFunction(int quesChoice)
{
	int pos, data, number;
	LinkedList lList = LinkedList();
	/*Data for ques5*/
	LinkedList lListNum1 = LinkedList();
	LinkedList lListNum2 = LinkedList();
	/*Data for ques7*/
	intersectionResult iRes;
	Node* node1_1 = new Node(1);
	Node* node1_2 = new Node(2);
	Node* node1_3 = new Node(3);
	Node* node2_1 = new Node(4);
	Node* node2_2 = new Node(5);
	Node* merge1 = new Node(6);
	Node* merge2 = new Node(7);

	if (quesChoice == 5)
	{
		lListNum1.insert(9);
		lListNum1.insert(7);
		lListNum1.insert(8);

		cout << "List num 1 is:";
		lListNum1.printll(lListNum1.head);
		cout << "\n";

		lListNum2.insert(6);
		lListNum2.insert(8);
		lListNum2.insert(5);
		cout << "List num 2 is:";
		lListNum2.printll(lListNum2.head);
		cout << "\n";
	}
	else if (quesChoice == 7)
	{
		node1_1->next = node1_2;
		node1_2->next = node1_3;
		node2_1->next = node2_2;
		node1_3->next = merge2;
		node2_2->next = merge2;
		merge1->next = merge2;
	}
	else
	{
		InitializeList(lList);
	}
	switch (quesChoice)
	{
	case 1:
		cout << "After remove duplicate the list is:" << "\n";
		lList.printll(removeDup(lList.head));
		break;
	case 2:
		cout << "Please enter your pos:";
		cin >> pos;
		cout << "Value from k to end are:";
		lList.printll(returnKth(lList.head, pos));
		break;
	case 3:
		cout << "Please enter your data:";
		cin >> data;
		cout << "new list:" << "\n";
		lList.printll(deleteMid(lList.head, data));
		break;
	case 4:
		cout << "Please enter partition:";
		cin >> number;
		cout << "Partition:" << "\n";
		lList.printll(partition(lList.head, number));
		break;
	case 5:
		cout << "Sum list is:";
		sumLists(lListNum1.head, lListNum2.head);
		break;
	case 6:
		cout << "Is list palindrome:" << checkPalindrome(lList.head);
		break;
	case 7:
		
		iRes = intersection(node1_1, node2_1);
		if (iRes.isIntersection)
		{
			cout << "2 list is intersection and intersection node has data:" << iRes.data;
		}
		else
		{
			cout << "2 list is not intersection";

		}
		break;

	case 8:
		cout << "Reverse List is:";
		lList.printll(reverseUseStack(lList.head));
		
		

		break;
	default:
		break;
	}
}

void Stack(int quesChoice)
{
	string insertS;
	switch (quesChoice)
	{
	case 1:
		cout << "Please insert the string:" << "\n";
		cin >> insertS;
		if (balanceParenthesis(insertS)) cout << "this is balance!\n";
		else cout << "this is unbalance!";
		break;
	case 2:
		checkMin();
		break;
	case 3:
		checkSetOfStack();
		break;
	case 4:
		checkMyQueue();
		break;
	case 5:
		checkSortStack();
		break;
	case 6:
		checkPetQueue();
		break;
	default:
		break;
	}
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

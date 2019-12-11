// CrackingInterviewPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "CIP.h"

using namespace std;

void ArrayandStrings(int);
void LinkedListFunction(int);


int main()
{
	int lessonChoice;
	int quesChoice;

    cout << "Welcome to workshop!\n";
	cout << "Choose your lesson:\n";
	cout << "	1. Array and Strings!\n";
	cout << "	2. Linked list!\n";

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

		cin >> quesChoice;
		LinkedListFunction(quesChoice);
		break;
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
	LinkedList lList = LinkedList();
	InitializeList(lList);

	switch (quesChoice)
	{
	case 1:
		cout << "After remove duplicate the list is:" << "\n";
		lList.printll(removeDup(lList.head));
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

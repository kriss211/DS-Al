#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "CIP.h"
#include <math.h>
using namespace std;

/*Self Solution: -> O(n^2) time and O(1) space
Don't use any other data structure*/
//bool checkUnique(string Sinput)
//{
//	bool isUnique = true;
//	for (int i = 0; i < Sinput.length() - 1; i++)
//	{
//		for (int j = i + 1; j < Sinput.length(); j++)
//			if (Sinput[i] == Sinput[j])
//			{
//				isUnique = false;
//				break;
//			}
//		if (!isUnique) break;
//	}
//	return isUnique;
//}

/*Other solution: One solution is to create an array of boolean values, where the 
flag at index i indicates whether character i in the alphabet is contained in the 
string. The second time you see this character you can immediately return false 
O(n) time and O(1) space */
bool checkUnique(string Sinput)
{
	bool char_set[256] = {false};

	if (Sinput.size() > 256) return false;
	for (int i = 0; i < Sinput.size(); i++)
	{
		int val = Sinput[i];
		if (char_set[val])
		{
			return false;
		}
		else
		{
			char_set[val] = true;
		}

	}
	return true;
}

//bool checkPermutation(string firstS, string secondS)
//{
//	bool isPermutation = false;
//	int index = 0;
//	if (firstS.length() == secondS.length())
//	{
//		while (index < secondS.length())
//		{
//			if (firstS[index] == secondS[secondS.length() - 1 - index])
//			{
//				index++;
//			}
//			else
//			{
//				break;
//			}
//			isPermutation = true;
//		}
//	}
//	return isPermutation;
//}

/*Other solution: sort 2 string then compare value of sorted string*/
bool checkPermutation(string firstS, string secondS)
{	
	char *cStr1 = new char[firstS.size() + 1]();
	char *cStr2 = new char[secondS.size() + 1]();
	int index = 0;
	if (firstS.size() != secondS.size()) return false;

	/*change string to array to use sort array method in algorithim lib*/
	firstS.copy(cStr1, firstS.size() + 1);
	secondS.copy(cStr2, secondS.size() + 1);
	sort(cStr1,cStr1 + firstS.size() + 1);
	sort(cStr2, cStr2 + secondS.size() + 1);
	
	for (int i = 0; i < firstS.size(); i++)
	{
		if (cStr1[i] != cStr2[i])
		{
return false;
		}
	}
	return true;
}

string URLify(int size)
{
	string Sinput = "h u y t      ";
	vector<int> space_array;
	for (int i = 0; i < size - 1; i++)
	{
		if (Sinput[i] == ' ')
		{
			space_array.push_back(i);
		}
	}

	for (int j = space_array.size() - 1; j >= 0; j--)
	{
		Sinput[space_array[j] + 1 + 2 * (j + 1)] = Sinput[space_array[j] + 1];
		Sinput[space_array[j] + 1 + 2 * (j + 1) - 1] = '0';
		Sinput[space_array[j] + 1 + 2 * (j + 1) - 2] = '2';
		Sinput[space_array[j] + 1 + 2 * (j + 1) - 3] = '%';
	}
	return Sinput;

}

/*PalindromePermutation is a string that can write the same from
foreward and backward*/
/*Solution 1: count number of char that has an odd count
IF number of char has odd count > 1 => not PalindromePermutation
ex: haedah is not (2 h, 2 a, 1 e, 1 d)*/
//bool checkPalindromePermutation(string Sinput)
//{
//	bool ret = true;
//
//	int flag = 0;
//	int index = 1;
//	int i = 0;
//
//	char *cStr = new char[Sinput.size() + 1]();
//	unsigned int *aaIndex = new unsigned int[Sinput.size()]();
//
//	Sinput.copy(cStr, Sinput.size() + 1);
//	sort(cStr, cStr + Sinput.size() + 1);
//
//	while (index < Sinput.size() - 1)
//	{
//		if (cStr[index] != cStr[index + 1])
//		{
//			aaIndex[i]++;
//			i++;
//		}
//		else
//		{
//			aaIndex[i]++;
//		}
//		index++;
//	}
//
//	for (int i = 0; i < Sinput.size(); i++)
//	{
//		if (aaIndex[i] % 2 != 0)
//		{
//			flag++;
//		}
//		if (flag > 1)
//		{
//			ret = false;
//			break;
//		}
//
//	}
//	return ret;
//}

/*Solution 2: use and interger number(Count) to check
Using 1 bit represent for a character
Check through the string if see this character toggle
respectively bit
The default value of bit is 0 => After go through all
the string if value of bit is 0 => character have an
even count else it has and odd count
How to check number of odd count:
(Count - 1) & count = 0 -> only one odd count
ex: 1000 - 1 = 0111 => 0111 & 1000 = 0 -> one odd count
10100 - 1 = 10011 => 10011 & 10100 != 0 -> > 1 odd count*/

bool checkPalindromePermutation(string Sinput)
{
	bool ret = true;
	long oddCount = 0;
	long checkValue;
	for (int i = 0; i < Sinput.size(); i++)
	{
		oddCount ^= (1 << ((int)Sinput[i] - 97));
	}

	checkValue = ((oddCount - 1) & oddCount);

	if (checkValue != 0)
	{
		ret = false;
	}

	return ret;
}

/*Self solution: time O(n*m)*/
//bool OneAway(string firstS, string secondS)
//{
//	int count = 0;
//	bool ret = true;
//	for (int i = 0; i < firstS.size() - 1; i++)
//	{
//		for (int j = 0; j < secondS.size() - 1; j++)
//		{
//			if (firstS[i] != secondS[j])
//			{
//				count++;
//			}
//			if (count == 2)
//			{
//				ret = false;
//				break;
//			}
//		}
//		if (ret == false) break;
//	}
//	return ret;
//}

/*better solution: time O(n)*/
bool OneAway(string firstS, string secondS)
{
	int deltaLenght = firstS.size() - secondS.size();
	int indexSmaller = 0;
	int indexBigger = 0;
	bool foundFirstDiff = false;

	/*check if delta lenght is bigger than 1*/
	if (abs(deltaLenght) > 1) return false;

	string smallerStr = firstS.size() < secondS.size() ? firstS : secondS;
	string biggerStr = firstS.size() < secondS.size() ? secondS : firstS;

	while (indexSmaller < smallerStr.size() && indexBigger < biggerStr.size())
	{
		if (smallerStr[indexSmaller] != biggerStr[indexBigger])
		{
			if (foundFirstDiff)
			{
				return false;
			}
			foundFirstDiff = true;
		}
		else
		{
			indexSmaller++;
		}
		indexBigger++;
	}
	return true;
}

/*self solution: use insert to concatrate an string -> 
took more step to handle creating a new string*/
//string StringCompression(string Sinput)
//{
//	int index = 0;
//	int countRepeated = 1;
//	string compressedStr = "";
//	int newStrIndex = 0;
//	int offset = 0;
//	while (index < Sinput.size())
//	{
//		if (Sinput[index] == Sinput[index + 1])
//		{
//			countRepeated++;
//		}
//		else
//		{
//			compressedStr.insert(newStrIndex,(Sinput[index]) + to_string(countRepeated));
//			while (countRepeated / 10 != 0)
//			{
//				offset++;
//				countRepeated = countRepeated / 10;
//			}
//			newStrIndex += offset + 2;
//			offset = 0;
//			countRepeated = 1;
//		}
//
//		index++;
//	}
//	return compressedStr;
//}

/*better solution: use append to concatrate new string 
to end of target string*/
string StringCompression(string Sinput)
{
	int index = 0;
	int countRepeated = 1;
	string compressedStr = "";
	int newStrIndex = 0;
	int offset = 0;
	while (index < Sinput.size())
	{
		if (Sinput[index] == Sinput[index + 1])
		{
			countRepeated++;
		}
		else
		{
			compressedStr.append((Sinput[index]) + to_string(countRepeated));
			countRepeated = 1;
		}

		index++;
	}
	return compressedStr;
}


void ZeroMatrix()
{
	int width = 0;
	int height = 0;
	int temp = 0;
	int input;
	

	cout << "Insert width:";
	cin >> width;
	cout << "Insert height:";
	cin >> height;

	int **matrix = new int*[height];
	for (int j = 0; j < height; j++)
	{
		matrix[j] = new int[width];
	}

	int *rowWithZero = new int[height];
	int *colWithZero = new int[width];

	cout << "Insert matrix by row: ";
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cin >> input;
			matrix[i][j] = input;
		}
	}

	cout << "Old matrix by row: \n";
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (matrix[i][j] == 0)
			{
				rowWithZero[i] = 1;
				colWithZero[j] = 1;
			}
		}
	}

	for (int i = 0; i < height; i++)
	{
		if (rowWithZero[i] == 1)
		{
			for (int j = 0; j < width; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < width; i++)
	{
		if (colWithZero[i] == 1)
		{
			for (int j = 0; j < height; j++)
			{
				matrix[j][i] = 0;
			}
		}
	}
	cout << "New matrix by row: \n";

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	
	


}

bool StringRotation(string firstS, string secondS)
{
	string concatStr = secondS + secondS;
	return isSubstring(firstS, concatStr);
}

bool isSubstring(string firstS, string concatStr)
{
	bool ret = false;
	if (concatStr.find(firstS) != string::npos)
	{
		ret = true;
	}
	return ret;

}

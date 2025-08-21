#include "Algorithms_CodingPractice.h"

#include <assert.h>
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <set>
#include <math.h>
#include <map>
#include <utility>
#include <vector>

#include "../DataStructures/BinaryTree.h"
#include "../DataStructures/RingBuffer.h"

namespace Algorithms
{
namespace CodingPractice
{

/* Daily Coding Problem - October 4 2019
Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
Bonus: Can you do this in one pass?
*/

bool arrayPairCanSumToNumber(int* array, size_t arraySize, int numberAsSum)
{
	std::map<int, int> numberMap;
	std::map<int, int>::iterator it;
	for (size_t i = 0; i < arraySize; ++i)
	{
		it = numberMap.find(array[i]);
		if (it != numberMap.end())
		{
			++(it->second);
		}
		else
		{
			numberMap.insert(std::pair<int, int>(i, 1));
		}
	}
	
	for (size_t i = 0; i < arraySize; ++i)
	{
		int diffToSearch = numberAsSum - array[i];
		it = numberMap.find(diffToSearch);
		
		if (diffToSearch == array[i])
		{
			assert(it != numberMap.end());
			return it->second > 1;
		}
		else if (it != numberMap.end())
		{
			return true;
		}
	}

	return false;
}

std::string ReverseString(const char* inString)
{
	int iterator = -1;
	while(inString[++iterator] != 0)
	{ }

	
	std::string reversedString;
	--iterator;
	int i = 0;
	while (iterator > -1)
	{
		reversedString[i++] = inString[iterator--];
	}
	reversedString[i] = 0;

	return reversedString;
}

void ReverseStringInPlace(char* inString)
{
	int iterator = -1;
	while(inString[++iterator] != 0)
	{}

	std::string reversedString;
	--iterator;
	int i = 0;
	while (iterator > i)
	{
		char temp = inString[iterator];
		inString[iterator] = inString[i];
		inString[i] = temp;
		--iterator;
		++i;
	}
}

struct Vec4
{
	Vec4(float inX, float inY, float inZ, float inW) : x(inX), y(inY), z(inZ), w(inW)
	{}

	float x, y, z, w;
};

float dot(Vec4 lhs, Vec4 rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}

bool VectorAngleCheck(Vec4 aVec, Vec4 bVec, float angle)
{
	float dotProduct = dot(aVec, bVec);
	float cosCalcAngleSqrd = (dotProduct * dotProduct) / ( dot(aVec, aVec) * dot(bVec, bVec) );
	float cosInAngleSqrd = cosf(angle) * cosf(angle);

	return cosCalcAngleSqrd > cosInAngleSqrd;
}

/*Daily Coding Problem #418 Nov 27 '20
MegaCorp wants to give bonuses to its employees based on how many lines of codes they have written. They would like to give the smallest positive amount to each worker consistent 
with the constraint that if a developer has written more lines of code than their neighbor, they should receive more money.

Given an array representing a line of seats of employees at MegaCorp, determine how much each one should get paid.

For example, given [10, 40, 200, 1000, 60, 30], you should return [1, 2, 3, 4, 2, 1].*/
void DetermineEmployeeBonus(int* const i_employeeLOC, const size_t i_numEmployees, std::vector<int>& o_employeeBonus)
{
	assert(i_employeeLOC != nullptr && "Input array of employee's lines of code was null.");
	if (o_employeeBonus.capacity() - o_employeeBonus.size() < i_numEmployees)
	{
		o_employeeBonus.reserve(i_numEmployees);
	}
	
	o_employeeBonus.emplace_back(1);
	for (size_t i = 1; i < i_numEmployees; ++i)
	{
		if (i_employeeLOC[i] > i_employeeLOC[i - 1])
		{
			o_employeeBonus.emplace_back(o_employeeBonus[i - 1] + 1);
		}
		else
		{
			o_employeeBonus.emplace_back(o_employeeBonus[i - 1] - 1);
		}
	}

}

/*Daily Coding Problem #424 Dec 2 '20
Given an array of integers in which two elements appear exactly once and all other elements appear exactly twice, find the two elements that appear only once.
For example, given the array [2, 4, 6, 8, 10, 2, 6, 10], return 4 and 8. The order does not matter.
Follow-up: Can you do this in linear time and constant space?*/
std::pair<int, int> ElementsAppearOnceUsingStdSet(int* i_array, size_t i_size)
{
	std::set<int> singleAppearanceElements;
	for (unsigned int i = 0; i < i_size; ++i)
	{
		auto foundIt = singleAppearanceElements.find(i_array[i]);
		if (foundIt == singleAppearanceElements.end())
		{
			singleAppearanceElements.insert(i_array[i]);
		}
		else
		{
			singleAppearanceElements.erase(i_array[i]);
		}
	}

	assert(singleAppearanceElements.size() == 2 && "More than 2 elements appeared only once or elements appeared more than twice.");
	std::pair<int, int> result = std::make_pair(*singleAppearanceElements.begin(), *(++singleAppearanceElements.begin()) );
	return result;
}

//Does not check for ill-formed input - could have more than 2 elements appearing only once
std::array<int, 2> ElementsAppearOnceUsingSort(int* i_array, size_t i_size)
{
	std::sort(i_array, i_array + i_size);
	std::array<int, 2> singleAppearanceElements;
	unsigned int elementsFound = 0;
	size_t it = 0;
	while (elementsFound < 2 && it < i_size - 1)
	{
		int current = i_array[it];
		if (i_array[it + 1] == current)
		{
			it += 2;
		}
		else
		{
			singleAppearanceElements[elementsFound] = i_array[it];
			++elementsFound;
			++it;
		}
	}
	if (elementsFound < 2)
	{
		singleAppearanceElements[elementsFound] = i_array[it];
		++elementsFound;
	}

	return singleAppearanceElements;
}

/*Daily Coding Problem #426 - Dec 4 '20
Given a binary tree, return the level of the tree with minimum sum.*/
unsigned int GetTreeLevelOfMinimumSum(DataStructures::BinaryTree* i_tree)
{
	int maxLeafNodes = (i_tree->GetNumNodes() + 1) / 2;
	DataStructures::RingBuffer<DataStructures::BinaryTreeNode*> nodeBuffer(maxLeafNodes);
	DataStructures::BinaryTreeNode* treeRoot = i_tree->GetTreeRoot();
	if (treeRoot)
	{
		if (treeRoot->m_leftChild)
		{
			nodeBuffer.Write(i_tree->GetTreeRoot()->m_leftChild);
		}
		if (treeRoot->m_rightChild)
		{
			nodeBuffer.Write(i_tree->GetTreeRoot()->m_rightChild);
		}
	}
	else
	{
		return 0;
	}
	unsigned int currentLevel = 1;
	unsigned int levelOfMinimumSum = 1;
	uint64_t minimumSum = UINT64_MAX;
	while (!nodeBuffer.empty())
	{
		std::cout << "\nLevel " << currentLevel << " ";
		size_t currentLevelSize = nodeBuffer.size();
		unsigned int currentLevelSum = 0;
		for (size_t i = 0; i < currentLevelSize; ++i)
		{
			DataStructures::BinaryTreeNode* pCurrNode = nodeBuffer.Read();
			std::cout << pCurrNode->m_data << " ";
			currentLevelSum += pCurrNode->m_data;
			if (pCurrNode->m_leftChild)
			{
				nodeBuffer.Write(pCurrNode->m_leftChild);
			}
			if (pCurrNode->m_rightChild)
			{
				nodeBuffer.Write(pCurrNode->m_rightChild);
			}
		}
		std::cout << " Level Sum: " << currentLevelSum;
		if (currentLevelSum < minimumSum)
		{
			minimumSum = currentLevelSum;
			levelOfMinimumSum = currentLevel;
		}
		++currentLevel;
	}
	
	return levelOfMinimumSum;
}

/*Daily Coding Problem #431 Dec 9 '20
Create a basic sentence checker that takes in a stream of characters and determines whether they form valid sentences. If a sentence is valid, the program should print it out.
*/
bool CheckAndPrintValidSentence(const char*& i_sentence)
{
	if (i_sentence[0] >= 'A' && i_sentence[0] <= 'Z' && ((i_sentence[1] >= 'a' && i_sentence[1] <= 'z') || i_sentence[1] == ' '))
	{
		unsigned int i = 2;
		while (true)
		{
			if (i_sentence[i] >= 'a' && i_sentence[i] <= 'z')
			{
				++i;
			}
			else if (i_sentence[i] == ' ')
			{
				if (i_sentence[i + 1] >= 'a' && i_sentence[i + 1] <= 'z')
				{
					i += 2;
				}
				else
				{
					break;
				}
			}
			else if (i_sentence[i] == ',' || i_sentence[i] == ';' || i_sentence[i] == ':')
			{
				if (i_sentence[i + 1] == ' ' && (i_sentence[i + 2] >= 'a' && i_sentence[i + 2] <= 'z'))
				{
					i += 3;
				}
				else
				{
					break;
				}
			}
			else if (i_sentence[i] == '.' || i_sentence[i] == '?' || i_sentence[i] == '!')
			{
				if (i_sentence[i + 1] == '\0')
				{
					std::cout << "\nSentence is valid: " << i_sentence << "\n";
					return true;
				}
			}
			else
			{
				break;
			}
		}
	}
	//Sentence is invalid if control reaches here.
	std::cout << "\nNot a valid sentence\n";
	return false;
}

} // namespace CodingPractice
} // namespace Algorithms
#include "Algorithms_CodingPractice_2022.h"

#include "../DataStructures/BinaryTree.h"

#include <deque>
#include <iostream>
#include <string>
#include <utility>

namespace Algorithms
{
namespace CodingPractice
{
	std::pair<int, int> StockTradeBestDays(std::vector<int>& i_stockPriceRecord)
	{
		

		return std::make_pair<int, int>(0, 0);
	}

	void PrintTreeCousins(DataStructures::BinaryTreeNode* rootNode, int searchValue)
	{
		if (rootNode->m_leftChild == nullptr && rootNode->m_rightChild == nullptr)
		{
			std::cout << "Root node has no children. No cousins to print.\n";
			return;
		}

		DataStructures::BinaryTreeNode* currentNode = rootNode;
		DataStructures::BinaryTreeNode* childNode = nullptr;
		int levelOfParents = 0;

		while (true)
		{
			if (searchValue < currentNode->m_data)
			{
				childNode = currentNode->m_leftChild;
				
			}
			else
			{
				childNode = currentNode->m_rightChild;
			}

			if (childNode == nullptr || childNode->m_data == searchValue)
			{
				break;
			}
			else
			{
				currentNode = childNode;
			}

			++levelOfParents;
		}

		if (childNode == nullptr)
		{
			std::cout << "Search value not found. No cousins to print.\n";
		}

		DataStructures::BinaryTreeNode* nodeToAvoid = currentNode;

		std::deque<DataStructures::BinaryTreeNode*> levelNodes1;
		std::deque<DataStructures::BinaryTreeNode*> levelNodes2;
		std::deque<DataStructures::BinaryTreeNode*>* parentLevelNodes = &levelNodes1;
		std::deque<DataStructures::BinaryTreeNode*>* childLevelNodes = &levelNodes2;
		(*parentLevelNodes).emplace_back(rootNode);

		int i = 0;
		while (i <= levelOfParents)
		{
			(*childLevelNodes).clear();
			for (DataStructures::BinaryTreeNode* pTreeNode : *parentLevelNodes)
			{
				if (pTreeNode == nodeToAvoid)
				{
					continue;
				}

				if (pTreeNode->m_leftChild)
				{
					(*childLevelNodes).emplace_back(pTreeNode->m_leftChild);
				}
				if (pTreeNode->m_rightChild)
				{
					(*childLevelNodes).emplace_back(pTreeNode->m_rightChild);
				}
			}

			std::swap(parentLevelNodes, childLevelNodes);
			++i;
		}

		std::swap(parentLevelNodes, childLevelNodes);
		std::cout << "Cousins of search value:\n";
		for (DataStructures::BinaryTreeNode* pTreeNode : *childLevelNodes)
		{
			std::cout << pTreeNode->m_data << " ";
		}
	}

	unsigned int CountBinaryTreeNodes(DataStructures::BinaryTreeNode* rootNode)
	{
		if (rootNode == nullptr)
		{
			return 0;
		}

		unsigned int numTreeNodes = 1;
		unsigned int currentLevelNodes = 1;
		unsigned int numChildrenMultiplier = 2;

		DataStructures::BinaryTreeNode* currentNode = rootNode->m_leftChild;
		while (currentNode != nullptr)
		{
			currentLevelNodes *= numChildrenMultiplier;
			numTreeNodes += currentLevelNodes;
			currentNode = currentNode->m_leftChild;
		}

		return numTreeNodes;
	}

	std::string RunLengthEncoding(std::string inputString)
	{
		std::string encodedString = "";
		if (inputString.length() == 0)
		{
			return encodedString;
		}

		char currentChar = inputString[0];
		unsigned int consecutiveLength = 0;
		size_t inputLength = inputString.length();
		for (size_t index = 0; index <= inputLength; ++index)
		{
			if (index == inputString.length() || inputString[index] != currentChar)
			{
				char length = 48 + consecutiveLength;
				encodedString += length;
				encodedString += currentChar;

				consecutiveLength = 1;
				if (index != inputString.length())
				{
					currentChar = inputString[index];
				}
			}
			else
			{
				++consecutiveLength;
			}
		}

		std::cout << "Input string: " << inputString << ", Encoded string: " << encodedString << "\n";
		return encodedString;
	}

	std::string RunLengthDecoding(std::string encodedString)
	{
		std::string decodedString = "";
		if (encodedString.length() == 0)
		{
			return decodedString;
		}

		size_t encodedStringLength = encodedString.length();

		size_t decodedLength = 0;
		for (size_t index = 0; index < encodedStringLength; index += 2)
		{
			decodedLength += static_cast<size_t>(encodedString[index]) - 48;
		}
		decodedString.reserve(decodedLength);

		for (size_t index = 0; index < encodedStringLength; index += 2)
		{
			size_t consecutiveLength = static_cast<size_t>(encodedString[index]) - 48;
			char currentChar = encodedString[index + 1];

			for (size_t i = 0; i < consecutiveLength; ++i)
			{
				decodedString.push_back(currentChar);
			}
		}

		std::cout << "Encoded string: " << encodedString << ", Decoded string: " << decodedString << std::endl;
		return decodedString;
	}

	std::string SurroundWithA(std::string i_str)
	{
		constexpr size_t numMaxSurrounders = 2;
		constexpr char surroundingChar = 'a';

		const size_t inputStrLength = i_str.length();
		const int sizeToReserve = (numMaxSurrounders + 1) * inputStrLength + numMaxSurrounders;

		std::string surroundedStr("");
		surroundedStr.reserve(sizeToReserve);

		size_t numSurrounders = numMaxSurrounders;
		for (size_t i = 0; i < inputStrLength; ++i)
		{
			if (i_str[i] == surroundingChar)
			{
				--numSurrounders;
			}
			else
			{
				while (numSurrounders > 0)
				{
					surroundedStr.push_back(surroundingChar);
					--numSurrounders;
				}

				surroundedStr.push_back(i_str[i]);
				numSurrounders = numMaxSurrounders;
			}
		}

		while (numSurrounders > 0)
		{
			surroundedStr.push_back(surroundingChar);
			--numSurrounders;
		}

		return surroundedStr;
	}

}
}



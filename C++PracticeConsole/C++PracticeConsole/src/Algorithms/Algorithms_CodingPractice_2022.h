#pragma once

#include <string>
#include <vector>

namespace DataStructures
{
	class BinaryTreeNode;
}

namespace Algorithms
{
namespace CodingPractice
{
	std::pair<int, int> StockTradeBestDays(std::vector<int>& i_stockPriceRecord);
	void PrintTreeCousins(DataStructures::BinaryTreeNode* rootNode, int searchValue);

	std::string RunLengthEncoding(std::string inputString);
	std::string RunLengthDecoding(std::string encodedString);
}
}

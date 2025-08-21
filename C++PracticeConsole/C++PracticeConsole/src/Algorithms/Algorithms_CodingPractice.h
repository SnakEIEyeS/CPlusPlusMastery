#pragma once

#include <vector>

namespace DataStructures
{
	class BinaryTree;
}

namespace Algorithms
{
namespace CodingPractice
{
	bool arrayPairCanSumToNumber(int* array, size_t arraySize, int numberAsSum);

	void DetermineEmployeeBonus(int* const i_employeeLOC, const size_t i_numEmployees, std::vector<int>& o_employeeBonus);

	//Daily Coding Problem #424 Dec 2 '20
	std::pair<int, int> ElementsAppearOnceUsingStdSet(int* i_array, size_t i_size);
	std::array<int, 2> ElementsAppearOnceUsingSort(int* i_array, size_t i_size);

	unsigned int GetTreeLevelOfMinimumSum(DataStructures::BinaryTree* i_tree);

	//Daily Coding Problem #431 Dec 9 '20
	bool CheckAndPrintValidSentence(const char*& i_sentence);
}
}

#include <array>
#include <chrono>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include "string.h"
#include <utility>
#include <vector>

#include "Algorithms/Algorithms_CodingPractice.h"
#include "Algorithms/Algorithms_CodingPractice_2021.h"
#include "Algorithms/Algorithms_CodingPractice_2022.h"
#include "Entity.h"
#include "Inheritance.h"
#include "DataStructures/BinaryTree.h"
#include "DataStructures/Object.h"

#define MAXTEST(l,r) ((l > r) ? l : r)

extern int i_stat;

void FizzBuzz(int i)
{
	std::string result;
	if (i % 3 == 0)
	{
		result += "Fizz";
	}
	if (i % 15 == 0)
	{
		result += "Buzz";
	}
	if (result.empty())
	{
		result = "Empty";
	}
	std::cout << "Resulting string is: " << result << std::endl;
}

class SizeTest
{
	enum ObjectBitFlags
	{
		OBF_ACTIVE = 0x0001,
		OBF_INVULNERABLE = 0x0002,
		OBF_HIDDEN = 0x0004,
		OBF_STEALTH_PROVIDER = 0x0008
	};
	int xSize;
};

class VecTest
{
public:
	VecTest(int n)
	{
		/*floatvec.reserve(n);
		for (int i = 0; i < n; ++i)
		{
			floatvec.emplace_back(std::vector<float>());
			floatvec[i].reserve(n);
			for (int j = 0; j < n; ++j)
			{
				floatvec[i].emplace_back(1.f);
			}
			
			//floatvec.emplace_back(1.f);
		}*/
		
	}
	std::vector<char> floatvec[16];
};

void DummyFunc()
{
	std::cout << "DummyFunc ran\n";
}

void fun(int*& p)
{
	static int q = 10;
	p = &q;
}

void OctreeTest();
void VectorPointerTesting();

void ReverseSentence(std::string inputStr);
void itoa(int x);

class AJ
{
public:
	virtual void AJVir() = 0;
};

class BL : public AJ
{
public:
	virtual void AJVir() override { std::cout << "BL\n"; }
};

class CL : public AJ
{
public:
	virtual void AJVir() override { std::cout << "CL\n"; }
};

class DL : public BL, CL
{
public:
	//virtual void AJVir() override { std::cout << "DL\n"; }
};

int main()
{
	std::cout << i_stat << std::endl;
	DL* dlTest = new DL(); 
	//dlTest->AJVir(); //Compiler error: ambiguous access of AJVir
	dlTest->BL::AJVir();

	FizzBuzz(1);
	//Read string functions strcat, strcat_s, strncpy etc.
	std::cout << "Size: " << sizeof(SizeTest) << "\n";
	char testASC = 65;
	std::cout << std::endl << testASC << std::endl;

	void(*func)(void) = &DummyFunc;
	func();

	VecTest testerVecter(82);
	std::cout << "size of VecTest: " << sizeof(VecTest) << "\n";
	std::cout << "size of testerVecter: " << sizeof(testerVecter) << "\n";
	std::cout << "size of floatvec in testerVecter: " << sizeof(testerVecter.floatvec[3]) << "\n";
	std::cout << "----------------------\n";
	Base* multOverride = new Lvl2();
	multOverride->PrintClass();
	delete multOverride;
	
	std::vector<int> intVec;
	intVec.reserve(3);
	intVec.push_back(1);
	intVec.push_back(2);
	intVec.push_back(3);

	//int employeeLOC[5] = { 100, 350, 765, 87, 109 };
	int employeeLOC[6] = { 10, 40, 200, 1000, 60, 30 };
	std::vector<int> employeeBonus;
	Algorithms::CodingPractice::DetermineEmployeeBonus(employeeLOC, sizeof(employeeLOC)/sizeof(employeeLOC[0]), employeeBonus);
	std::vector<int>::iterator it = employeeBonus.begin();
	for (int bonus : employeeBonus)
	{
		std::cout << "Employee Bonus " << bonus << "\n";
	}

	int elementsOnce[] = { 13, 9, 8, 2, 4, 6, 8, 10, 2, 6, 10, 4, 9, 13, 17, 14 };
	auto eleOnceUsingSort = Algorithms::CodingPractice::ElementsAppearOnceUsingSort(elementsOnce, sizeof(elementsOnce) / sizeof(elementsOnce[0]));
	std::cout << "Elements appearing once using sort: " << eleOnceUsingSort[0] << " " << eleOnceUsingSort[1] << "\n";

	auto eleOnceUsingSet = Algorithms::CodingPractice::ElementsAppearOnceUsingStdSet(elementsOnce, sizeof(elementsOnce) / sizeof(elementsOnce[0]));
	std::cout << "Elements appearing once using set: " << eleOnceUsingSet.first << " " << eleOnceUsingSet.second << "\n";

	int treeElements[] = { 30, 1135, 19, 1127, 212, 491, 82, 43, 40, 55, 96, 1, 14, 17, 21, 29 };
	DataStructures::BinaryTree binaryTree;
	size_t numTreeElements = sizeof(treeElements) / sizeof(treeElements[0]);
	for (unsigned int i = 0; i < numTreeElements; ++i)
	{
		binaryTree.Insert(treeElements[i]);
	}
	unsigned int treeLevelMinSum = Algorithms::CodingPractice::GetTreeLevelOfMinimumSum(&binaryTree);
	std::cout << "\nBinary Tree level with minimum sum = " << treeLevelMinSum << "\n";

	const char* sentenceForValidity = "I is a, wlion!";
	Algorithms::CodingPractice::CheckAndPrintValidSentence(sentenceForValidity);

	VectorPointerTesting();

	//R* DFS City Visit
	std::vector<int> cityConnections{0,9,0,2,6,8,0,8,3,0};
	int longestPathResult = Algorithms::CodingPractice::LongPath(cityConnections);
	std::cout << "Longest path = " << longestPathResult << "\n";

	std::cin.get();


	//delete e;

}

void VectorPointerTesting()
{
	std::cout << "\n\nVector pointer testing\n";
	std::vector<std::list<int>*>* pVectorTest = new std::vector<std::list<int>*>();
	//std::vector<std::list<int>*>* pVectorTest = new std::vector<std::list<int>*>(10);
	pVectorTest->reserve(10);
	for (size_t i = 0; i < 10; ++i)
	{
		pVectorTest->emplace_back(new std::list<int>);
		//(*pVectorTest)[i] = new std::list<int>();
	}
	size_t vecSize = pVectorTest->size();
	//for (auto eleList : *pVectorTest)
	for (size_t i = 0; i < vecSize; ++i)
	{
		for (int j = 1; j <= 10; ++j)
		{
			(*pVectorTest)[i]->push_back(j);
		}
	}
	for (size_t i = 0; i < vecSize; ++i)
	{
		for (auto listIt = (*pVectorTest)[i]->begin(); listIt != (*pVectorTest)[i]->end(); ++listIt)
		{
			std::cout << *listIt << "\n";

		}
	}
}

bool DetUnique(char* i_sent)
{
	i_sent[0] = '1';
	i_sent[5] = '2';

	return true;
}

void OctreeTest()
{

}

void ReverseSentence(std::string inputStr)
{
	size_t inputLength = inputStr.length();
	std::string revStr = "";
	revStr.reserve(inputStr.length());

	size_t writeIdx = 0;
	size_t startIdx = inputLength - 1;
	size_t endIdx = inputLength - 1;
	while (startIdx > 0)
	{
		if (inputStr.at(startIdx) == ' ')
		{
			for (size_t i = startIdx + 1; i <= endIdx; ++i, ++writeIdx)
			{
				revStr.at(writeIdx) = inputStr.at(i);
			}
			if (writeIdx < inputLength)
			{
				revStr.at(writeIdx++) = ' ';
			}
		}

		--startIdx;
	}

	std::cout << "Reversed sentence: " << revStr << "\n";
	
}

void itoa(int x);

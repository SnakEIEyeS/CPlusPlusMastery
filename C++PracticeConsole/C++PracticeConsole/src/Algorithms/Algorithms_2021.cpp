#include "Algorithms_CodingPractice_2021.h"

#include <list>
#include <stack>
#include <vector>

int i_stat = 9;

namespace Algorithms
{
namespace CodingPractice
{

	int LongPath(std::vector<int>& i_conns)
	{
		//iterate 0 to n-1 and add children in adjLists
		size_t inVectorSize = i_conns.size();
		std::vector<std::list<int>> adjLists(inVectorSize);
		for (size_t i = 1, inVectorSize = i_conns.size(); i < inVectorSize; ++i)
		{
			int parent = i_conns[i];
			adjLists[parent].push_back(i);
		}

		//dfs and keep track of the longest path
		std::stack<int> dfsStack;
		dfsStack.push(0);
		unsigned int longestPathLength = 0;
		unsigned int currentPathLength = 1;
		bool oddCityVisited = false;
		while (!dfsStack.empty())
		{
			int stackTop = dfsStack.top();
			if (!adjLists[stackTop].empty())
			{
				int cityToAdd = adjLists[stackTop].front();
				if (cityToAdd % 2 == 0 || !oddCityVisited)
				{
					dfsStack.push(cityToAdd);
					++currentPathLength;
					//if adding odd set flag
					if (cityToAdd % 2 != 0)
					{
						oddCityVisited = true;
					}
				}
				adjLists[stackTop].pop_front();

			}
			else
			{
				//if popping odd reset flag
				if (stackTop % 2 != 0)
				{
					oddCityVisited = false;
				}
				dfsStack.pop();
				if (currentPathLength > longestPathLength)
				{
					longestPathLength = currentPathLength;
				}
				--currentPathLength;
			}

		}

		return longestPathLength;
	}

}
}

class ptrOther;

void VectorDeclare::SetPointer(ptrDeclare* i_ptr)
{
	m_ptr = i_ptr;

	ptrOther* otherPtr = reinterpret_cast<ptrOther*>(i_ptr);
}

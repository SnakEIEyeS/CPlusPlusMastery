#pragma once

#include <vector>

namespace Algorithms
{
namespace CodingPractice
{
	int LongPath(std::vector<int>& i_conns);
}
}

class ptrDeclare;
class VectorDeclare
{
public:
	void SetPointer(ptrDeclare* i_ptr);

private:
	ptrDeclare* m_ptr = nullptr;
};

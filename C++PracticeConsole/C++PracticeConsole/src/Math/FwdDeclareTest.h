#pragma once

//#include "Vector.h"
namespace Math
{
	class Vector3;
}
class FwdDeclareTest
{
public:
	inline void SetVec(Math::Vector3* i_pVec);

private:
	Math::Vector3* m_pVec;
};

#include "FwdDeclareTest-inl.h"

#pragma once

#include "Vector.h"

inline void FwdDeclareTest::SetVec(Math::Vector3 * i_pVec)
{
	m_pVec = i_pVec;
	Math::Vector3 testVec(0.0f, 0.0f, 0.4f);
}

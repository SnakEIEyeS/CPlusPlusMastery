#pragma once
//#include "FwdDeclareTest.h"

namespace Math
{
class Vector3
{
public:
	Vector3();
	~Vector3();
	Vector3(float x, float y, float z);

	float m_x;
	float m_y;
	float m_z;
};

class Vector4
{
public:
	float m_x, m_y, m_z, m_w;

};
}

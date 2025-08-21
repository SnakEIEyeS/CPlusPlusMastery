#include "AABB.h"

AABB::AABB()
{
}

AABB::~AABB()
{
}

AABB::AABB(Math::Vector3 minPos, Math::Vector3 maxPos) : m_minPos(minPos), m_maxPos(maxPos), 
m_center((maxPos.m_x - minPos.m_x)/2.f, (maxPos.m_y - minPos.m_y) / 2.f, (maxPos.m_y - minPos.m_y) / 2.f)
{
}

bool AABB::ContainsPoint(Math::Vector3 point)
{
	float xFromMin = point.m_x - m_minPos.m_x;
	float yFromMin = point.m_y - m_minPos.m_y;
	float zFromMin = point.m_z - m_minPos.m_z;

	if ((xFromMin) > 0.f && xFromMin <= (m_maxPos.m_x - m_minPos.m_x)
		&& yFromMin > 0.f && yFromMin <= (m_maxPos.m_y - m_minPos.m_y)
		&& zFromMin > 0.f && zFromMin <= (m_maxPos.m_z - m_minPos.m_z))
	{
		return true;
	}

	return false;
}

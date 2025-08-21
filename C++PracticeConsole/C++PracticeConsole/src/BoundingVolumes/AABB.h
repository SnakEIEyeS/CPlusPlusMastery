#pragma once
#include "../Math/Vector.h"

class AABB
{
public:
	AABB();
	~AABB();
	AABB(Math::Vector3 minPos, Math::Vector3 maxPos);

	//SHMANE TODO: probably make this a static function
	bool ContainsPoint(Math::Vector3 point);

	Math::Vector3 m_minPos;
	Math::Vector3 m_maxPos;
	Math::Vector3 m_center;
};

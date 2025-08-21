#pragma once

#include "../Math/Vector.h"

class Object
{
public:
	Object();
	
	~Object();

	Object(const float position[3]);

	Math::Vector3 GetPosition() const;

private:
	Math::Vector3 m_position;
};

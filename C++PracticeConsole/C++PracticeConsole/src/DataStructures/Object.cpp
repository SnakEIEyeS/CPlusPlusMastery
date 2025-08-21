#include "Object.h"

Object::Object()
{
}

Object::~Object()
{
}

Object::Object(const float position[3])
{
}

Math::Vector3 Object::GetPosition() const
{
	return m_position;
}

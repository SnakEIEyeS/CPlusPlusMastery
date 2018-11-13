#include "Entity.h"

Entity::Entity() : m_Name("Unknown")
{}

Entity::Entity(const char * i_Name) : m_Name(i_Name)
{}

Entity::~Entity()
{}

const char * Entity::GetName()
{
	return m_Name;
}

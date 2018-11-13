#pragma once

class Entity
{
public:
	Entity();

	Entity(const char* i_Name);

	~Entity();

	const char* GetName();

private:
	const char* m_Name;
};

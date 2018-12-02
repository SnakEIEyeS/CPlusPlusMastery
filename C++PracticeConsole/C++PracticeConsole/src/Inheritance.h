#pragma once

class Base
{
public:
	Base();
	~Base();

	int x;
	int* baseint = nullptr;
};

class Derived : public Base
{
public:
	Derived();
	~Derived();

	int* a = nullptr;
	int y;

	bool operator>(const Derived& i_rhs)
	{
		return true;
	}
};

#pragma once

class Base
{
public:
	Base();
	virtual ~Base();

	virtual void PrintClass();

	int x;
	int* baseint = nullptr;
};

class Derived : public Base
{
public:
	Derived();
	~Derived();

	void PrintClass() override;

	int* a = nullptr;
	int y;

	bool operator>(const Derived& i_rhs)
	{
		return true;
	}
};

class Lvl2 : public Derived
{
public:
	Lvl2();
	~Lvl2();

	//void PrintClass() override;

};

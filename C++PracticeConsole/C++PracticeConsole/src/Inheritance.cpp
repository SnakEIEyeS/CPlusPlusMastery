#include "Inheritance.h"

#include <iostream>

Base::Base() : x(9), baseint(new int(5))
{
	std::cout << "Creating Base \n";
	
}

Base::~Base()
{
	std::cout << "Destroying Base \n";

	if (baseint)
	{
		std::cout << "Deleting baseint in Base\n";
		delete baseint;
		baseint = nullptr;
	}
}

Derived::Derived() : a(new int(8)), y(10)
{
	std::cout << "Creating Derived \n";
	std::cout << x << std::endl;
}

Derived::~Derived()
{
	std::cout << "Destroying Derived \n";

	if (a)
	{
		delete a;
		a = nullptr;
	}
	if (baseint != nullptr)
	{
		delete baseint;
		baseint = nullptr;
	}
}

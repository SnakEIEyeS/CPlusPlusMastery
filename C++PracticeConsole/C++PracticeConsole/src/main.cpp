#include <iostream>

#include "Entity.h"
#include "Inheritance.h"

int main()
{
	std::cout << "Hello World!" << std::endl;

	Entity* e = new Entity("Shantanu");
	std::cout << e->GetName() << std::endl;

	//Base* b = new Base();
	//delete b;
	Derived* d = new Derived();
	delete d;

	std::cin.get();


	delete e;

}

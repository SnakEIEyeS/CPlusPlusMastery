#include <iostream>

#include "Entity.h"
#include "Inheritance.h"

#define MAXTEST(l,r) ((l > r) ? l : r)

int main()
{
	std::cout << "Hello World!" << std::endl;

	Entity* e = new Entity("Shantanu");
	std::cout << e->GetName() << std::endl;

	//Base* b = new Base();
	//delete b;
	Derived* d = new Derived();
	delete d;

	
	//int max_int = MAXTEST(1, 2);
	//std::cout << max_int << "\n";

	std::cin.get();


	delete e;

}

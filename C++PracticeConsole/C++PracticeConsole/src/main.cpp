#include <iostream>

#include "Entity.h"

int main()
{
	std::cout << "Hello World!" << std::endl;

	Entity* e = new Entity("Shantanu");
	std::cout << e->GetName() << std::endl;

	std::cin.get();


	delete e;

}

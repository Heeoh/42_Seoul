#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// subject test
	std::cout << "\033[0;35m" << "[ subject test ]" << "\033[0m" << std::endl; 
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;
	std::cout << std::endl;

	const int arraySize = 10;

	// construct animals
	std::cout << "\033[0;35m" << "[ constructing ]" << "\033[0m" << std::endl; 
	Animal *animals[arraySize];
	for (int i=0; i<arraySize; i++) {
		std::cout << "[" << i << "] " << std::endl;
		if (i % 2 == 0)
			animals[i] = new Dog();
		else 
			animals[i] = new Cat();
	}
	std::cout << std::endl;

	// destruct animals
	std::cout << "\033[0;35m" << "[ destructing ]" << "\033[0m" << std::endl; 
	for (int i=0; i<arraySize; i++) {
		std::cout << "[" << i << "] " << std::endl;
		delete animals[i];
	}
	std::cout << std::endl;

	// copy constructor
	std::cout << "\033[0;35m" << "[ copy constructor ]" << "\033[0m" << std::endl; 	
	Dog *org = new Dog();
	Dog *copied = new Dog(*org);
	std::cout << std::endl;

	// check deep copy
	std::cout << "\033[0;35m" << "[ deep copy ]" << "\033[0m" << std::endl; 	
	std::cout << org->getBrain() << std::endl;
	std::cout << copied->getBrain() << std::endl;
	std::cout << std::endl;

	std::cout << org->getBrain()->getIdea(0) << std::endl;
	std::cout << copied->getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	org->getBrain()->setIdea("new idea!!!", 0);
	std::cout << org->getBrain()->getIdea(0) << std::endl;
	std::cout << copied->getBrain()->getIdea(0) << std::endl;	
	std::cout << std::endl;

	// destructor
	std::cout << "\033[0;35m" << "[ destructing ]" << "\033[0m" << std::endl; 	
	delete org;
	delete copied;

	return 0;
}
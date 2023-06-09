#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// ex02 main
	// AAnimal *meta = new AAnimal();
	// std::cout << std::endl;
	AAnimal *dog = new Dog();
	std::cout << std::endl;
	AAnimal *cat = new Cat();
	std::cout << std::endl;

	Dog dog2 = Dog();
	std::cout << std::endl;
	Cat cat2 = Cat();
	std::cout << std::endl;

	// delete meta;
	// std::cout << std::endl;
	delete dog;
	std::cout << std::endl;
	delete cat;
	std::cout << std::endl;
	//*/

	/*/ ex01 main
	// subject test
	std::cout << "\033[0;35m" << "[ subject test ]" << "\033[0m" << std::endl; 
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;
	delete i;
	std::cout << std::endl;

	const int arraySize = 10;

	// construct animals
	std::cout << "\033[0;35m" << "[ constructing ]" << "\033[0m" << std::endl; 
	AAnimal *animals[arraySize];
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

	//*/

	return 0;
}
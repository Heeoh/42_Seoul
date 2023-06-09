#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// constructed
	std::cout << "\033[0;35m" << "[ constructed ]" << "\033[0m" << std::endl; 
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << std::endl;

	// check animal's type and sound
	std::cout << "\033[0;35m" << "[ animal's type and sound ]" << "\033[0m" << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	dog->makeSound();
	cat->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	// check wrong animal's type and sound
	std::cout << "\033[0;35m" << "[ wrong animal's type and sound ]" << "\033[0m" << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();
	wrongMeta->makeSound();	
	std::cout << std::endl;

	// destructed
	std::cout << "\033[0;35m" << "[ destructed ]" << "\033[0m" << std::endl; 
	delete meta;
	delete dog;
	delete cat;
	std::cout << std::endl;
	delete wrongMeta;
	delete wrongCat;
	std::cout << std::endl;

	return 0;
}
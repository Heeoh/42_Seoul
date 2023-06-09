#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->type = "Dog";
	std::cout << "Dog defalut constructor is called" << std::endl;
}

Dog::Dog(const Dog& obj) : Animal() {
	std::cout << "Dog copy constructor is called" << std::endl;
	*this = obj;
}

Dog& Dog::operator=(const Dog& obj) {
	if (this != &obj) {
		this->type = obj.getType();
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor is called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Dog says woof-woof!" << std::endl;
}
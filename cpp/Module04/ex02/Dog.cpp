#include "Dog.hpp"

Dog::Dog() : AAnimal() {
	std::cout << "Dog defalut constructor is called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& obj) : AAnimal() {
	std::cout << "Dog copy constructor is called" << std::endl;
	*this = obj;
}

Dog& Dog::operator=(const Dog& obj) {
	std::cout << "Dog operator= is called" << std::endl;
	if (this != &obj) {
		this->type = obj.getType();
		this->brain = new Brain(*(obj.getBrain()));
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor is called" << std::endl;
	delete brain;
}

void	Dog::makeSound() const {
	std::cout << "Dog says woof-woof!" << std::endl;
}

Brain*	Dog::getBrain() const {
	return this->brain;
}
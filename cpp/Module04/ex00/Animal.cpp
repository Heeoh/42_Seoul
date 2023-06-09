#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal default constructor is called" << std::endl;
}

Animal::Animal(const Animal& obj) {
	std::cout << "Animal copy constructor is called" << std::endl;	
	*this = obj;
}

Animal& Animal::operator=(const Animal& obj) {
	if (this != &obj) {
		this->type = obj.getType();
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor is called" << std::endl;
}

void	Animal::makeSound() const {
	std::cout << "Animal says nothing!" << std::endl;
}

std::string	Animal::getType() const {
	return this->type;
}
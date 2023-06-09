#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->type = "Cat";
	std::cout << "Cat defalut constructor is called" << std::endl;
}

Cat::Cat(const Cat& obj) : Animal() {
	std::cout << "Cat copy constructor is called" << std::endl;
	*this = obj;
}

Cat& Cat::operator=(const Cat& obj) {
	if (this != &obj) {
		this->type = obj.getType();
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor is called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Cat says meaw!" << std::endl;
}
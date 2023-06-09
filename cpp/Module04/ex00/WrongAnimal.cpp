#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Wrong Animal") {
	std::cout << "WrongAnimal default constructor is called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj) {
	std::cout << "WrongAnimal copy constructor is called" << std::endl;	
	*this = obj;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj) {
	if (this != &obj) {
		this->type = obj.getType();
	}
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor is called" << std::endl;
}

void	WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal says nothing!" << std::endl;
}

std::string	WrongAnimal::getType() const {
	return this->type;
}
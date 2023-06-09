#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
	std::cout << "AAnimal default constructor is called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& obj) {
	std::cout << "AAnimal copy constructor is called" << std::endl;	
	*this = obj;
}

AAnimal& AAnimal::operator=(const AAnimal& obj) {
	if (this != &obj) {
		this->type = obj.getType();
	}
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor is called" << std::endl;
}

std::string	AAnimal::getType() const {
	return this->type;
}
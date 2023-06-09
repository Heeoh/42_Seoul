#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	this->type = "WrongCat";
	std::cout << "WrongCat defalut constructor is called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj) : WrongAnimal() {
	std::cout << "WrongCat copy constructor is called" << std::endl;
	*this = obj;
}

WrongCat& WrongCat::operator=(const WrongCat& obj) {
	if (this != &obj) {
		this->type = obj.getType();
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor is called" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "WrongCat says meaw!" << std::endl;
}
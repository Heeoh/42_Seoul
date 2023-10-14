#include "Ice.hpp"

Ice::Ice() : AMateria() {
	// std::cout << "Ice defalut constructor is called" << std::endl;
	this->type = "ice";
}

Ice::Ice(const Ice& obj) : AMateria() {
	// std::cout << "Ice copy constructor is called" << std::endl;
	*this = obj;
}

Ice& Ice::operator=(const Ice& obj) {
	// std::cout << "Ice assignment operator is called" << std::endl;
	if (this != &obj)
		this->type = obj.getType();
	return *this;
}

Ice::~Ice() {
	// std::cout << "Ice destructor is called" << std::endl;
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

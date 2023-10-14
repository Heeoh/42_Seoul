#include "Cure.hpp"

Cure::Cure() : AMateria() {
	// std::cout << "Cure defalut constructor is called" << std::endl;
	this->type = "cure";
}

Cure::Cure(const Cure& obj) : AMateria() {
	// std::cout << "Cure copy constructor is called" << std::endl;
	*this = obj;
}

Cure& Cure::operator=(const Cure& obj) {
	// std::cout << "Cure assignment operator is called" << std::endl;
	if (this != &obj)
		this->type = obj.getType();
	return *this;
}

Cure::~Cure() {
	// std::cout << "Cure destructor is called" << std::endl;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

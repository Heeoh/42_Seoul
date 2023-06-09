#include "Cure.hpp"

Cure::Cure() : AMateria(), name("") {
	std::cout << "Cure default constructor is called" << std::endl;
}

Cure::Cure(const Cure& obj) : AMateria() {
	std::cout << "Cure copy constructor is called" << std::endl;	
	*this = obj;
}

Cure& Cure::operator= (const Cure& obj) {
	std::cout << "Cure operator= is called" << std::endl;
}

Cure::~Cure() {
	std::cout << "Cure destructor is called" << std::endl;
}

Cure::Cure(std::string const & type, std::string _name) : AMateria(type), name(_name) {
	std::cout << "Cure constructor with type and name parameters is called" << std::endl;
}

Cure*	Cure::clone() const {
	Cure* clone = new Cure(*this);
	return clone;
}

void	Cure::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << name << "*" << std::endl;
}
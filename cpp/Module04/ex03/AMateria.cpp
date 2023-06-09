#include "AMateria.hpp"

AMateria::AMateria() {
	std::cout << "Amateria dufault constructor is called" << std::endl;
	this->type = "AMateria";
}

AMateria::AMateria(const AMateria& obj) {
	std::cout << "Amateria copy constructor is called" << std::endl;
}

AMateria& AMateria::operator= (const AMateria& obj) {
	std::cout << "Amateria operator= is called" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "Amateria destructor is called" << std::endl;
}

AMateria::AMateria(std::string const & type) {
	std::cout << "Amateria constructor with type parameter is called" << std::endl;
	this->type = type;
}

std::string const &	AMateria::getType() const {
	return type;
}

void		AMateria::use(ICharacter& target) {

}
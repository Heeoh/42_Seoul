#include "AMateria.hpp"

AMateria::AMateria() : AMateria() {
	std::cout << "AMateria defalut constructor is called" << std::endl;
	this->type = "unknown";
}

AMateria::AMateria(const AMateria& obj) : AMateria() {
	std::cout << "AMateria copy constructor is called" << std::endl;
	*this = obj;
}

AMateria& AMateria::operator=(const AMateria& obj) {
	std::cout << "AMateria assignment operator is called" << std::endl;
	if (this != &obj) {
		this->type = obj.getType();
	}
	return *this;
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor is called" << std::endl;
}

AMateria::AMateria(std::string const & type) {
    std::cout << "AMateria constructor is called" << std::endl;
	this->type = type;
}

std::string const& AMateria::getType() const {

}

void AMateria::use(ICharacter& target) {

}
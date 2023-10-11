#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource() {
	// std::cout << "MateriaSource defalut constructor is called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& obj) : IMateriaSource() {
	// std::cout << "MateriaSource copy constructor is called" << std::endl;
	*this = obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj) {
	// std::cout << "MateriaSource assignment operator is called" << std::endl;
	// if (this != &obj) {

	// }
	return *this;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor is called" << std::endl;
}

void MateriaSource::learnMateria(AMateria*) {

}

AMateria* MateriaSource::createMateria(std::string const & type) {
    
}

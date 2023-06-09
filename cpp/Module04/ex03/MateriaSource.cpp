#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource() {
	std::cout << "MateriaSource default constructor is called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& obj) {
	std::cout << "MateriaSource copy constructor is called" << std::endl;
}

MateriaSource& MateriaSource::operator= (const MateriaSource& obj) {
	std::cout << "MateriaSource operator= is called" << std::endl;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor is called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria*) {

}

AMateria*	MateriaSource::createMateria(std::string const & type) {

}
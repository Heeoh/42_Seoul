#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource() {
	// std::cout << "MateriaSource defalut constructor is called" << std::endl;
	for (int i=0; i<4; i++) {
        this->memory[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& obj) : IMateriaSource() {
	// std::cout << "MateriaSource copy constructor is called" << std::endl;
	*this = obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj) {
	// std::cout << "MateriaSource assignment operator is called" << std::endl;
	if (this != &obj) {
        for (int i=0; i<4; i++) {
            this->memory[i] = obj.memory[i]->clone();
        }
    }
	return *this;
}

MateriaSource::~MateriaSource() {
	// std::cout << "MateriaSource destructor is called" << std::endl;
	for (int i=0; i<4; i++) {
        if (this->memory[i])
            delete this->memory[i];
    }
}

void MateriaSource::learnMateria(AMateria* m) {
	int idx = 0;
    for ( ; idx<4; idx++) {
        if (this->memory[idx] == NULL) 
            break;
    }

    if (idx >= 4) {
        // std::cout << "Memory is full." << std::endl;
        return;
    } 

    this->memory[idx] = m;
    // std::cout << "Learned a new materia " << m->getType() << "." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
   int idx = 0;
    for ( ; idx<4; idx++) {
		if (this->memory[idx] && this->memory[idx]->getType() == type)
			break;
    }

    if (idx >= 4) {
        // std::cout << "Cannot find " << type << "." << std::endl;
        return 0;
    } 

	AMateria* newMateria = this->memory[idx]->clone(); 
	// std::cout << "Created a new materia " << newMateria->getType() << "." << std::endl;
	return newMateria;
	
}

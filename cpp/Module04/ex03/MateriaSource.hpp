#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
public:
    MateriaSource();
    MateriaSource(const MateriaSource& obj);
    MateriaSource& operator=(const MateriaSource& obj);
    ~MateriaSource() {}
    
    virtual void learnMateria(AMateria*);
    virtual AMateria* createMateria(std::string const & type);
};

#endif
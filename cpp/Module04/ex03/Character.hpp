#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character: public ICharacter {
private:
    std::string name;
    AMateria* inventory[4];

public:
    Character();
    Character(const Character& obj);
    Character& operator=(const Character& obj);
    ~Character();

    Character(std::string name);
    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif
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
    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
    AMateria* getInventory(int idx) const;
};

#endif
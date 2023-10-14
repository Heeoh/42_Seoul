#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
    /*/ subject test
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    
    //*/

    // my test
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure()); // nothing happen

    ICharacter* me = new Character("me");
    for (int i=0; i<3; i++)
        me->equip(src->createMateria("ice"));
    me->unequip(1);
    me->unequip(3); // nothing happen
    for (int i=0; i<3; i++)
        me->equip(src->createMateria("cure")); // when i = 2, nothing happen

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    me->unequip(0);
    me->use(0, *bob); // nothing happen

    ICharacter* clone = new Character(*((Character *)me));
    clone->use(0, *bob);
    clone->use(1, *bob);

    delete clone;
    delete bob;
    delete me;
    delete src;
    return 0;
}
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
    // subject test
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
    
    // */

    /*/ my test
	std::cout << "\033[0;35m" << "[ materia source ]" << "\033[0m" << std::endl; 
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	std::cout << std::endl;
	
	AMateria* tmpForSrc = new Cure();
    src->learnMateria(tmpForSrc); 
	std::cout << std::endl;

	AMateria* tmpIce[3]; 
    for (int i=0; i<3; i++)
		tmpIce[i] = src->createMateria("ice");
	AMateria* tmpCure[3]; 
    for (int i=0; i<3; i++)
		tmpCure[i] = src->createMateria("cure");
	std::cout << std::endl;


	std::cout << "\033[0;35m" << "[ character - equip & unequip ]" << "\033[0m" << std::endl; 
    ICharacter* me = new Character("me");
	me->equip(tmpIce[0]);
	me->equip(tmpIce[1]);
	me->equip(tmpIce[2]);
	std::cout << std::endl;

    me->unequip(1);
    me->unequip(3); // nothing happen
	std::cout << std::endl;

	me->equip(tmpCure[0]);
	me->equip(tmpCure[1]);
	me->equip(tmpCure[2]); // nothing happen
	std::cout << std::endl;


	std::cout << "\033[0;35m" << "[ character - use ]" << "\033[0m" << std::endl; 
    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);
	std::cout << std::endl;

    me->unequip(0);
    me->use(0, *bob); // nothing happen
	std::cout << std::endl;


	std::cout << "\033[0;35m" << "[ character copy ]" << "\033[0m" << std::endl; 
    ICharacter* clone = new Character(*((Character *)me));

    clone->use(0, *bob);  // nothing happen
    clone->use(1, *bob);
	std::cout << std::endl;

	clone->equip(src->createMateria("ice"));
	clone->use(0, *bob);
	me->use(0, *bob); // nothing happen
	std::cout << std::endl;


	for (int i=0; i<4; i++)
		me->unequip(i);
	for (int i=0; i<3; i++) {
		delete tmpIce[i];
		delete tmpCure[i];
	}
	delete tmpForSrc;
    delete clone;
    delete bob;
    delete me;
    delete src;

	// */

    return 0;
}
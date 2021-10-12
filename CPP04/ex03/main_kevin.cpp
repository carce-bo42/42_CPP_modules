#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Materia.hpp"

int	main( void )
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;
	std::cout << "UNEQUIP" << std::endl;
	std::cout << std::endl;
	me->unequip(0);
	me->unequip(0);
	me->unequip(0);
	me->unequip(0);
	me->unequip(0);
	me->unequip(0);
	me->unequip(0);
	me->unequip(0);
	me->unequip(0);

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << std::endl;

	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->equip(tmp);
	std::cout << std::endl;

	Character*	a = new Character("AAAAAAAAAAA");
	Character*	b = new Character(*a);
	Character*	c = new Character("CCCCCCCCCCC");

	*c = *a;
	delete a;
	me->use(1, *b);
	me->use(0, *c);
	std::cout << std::endl;

	delete b;
	delete c;
	delete bob;
	delete me;
	delete src;

	return 0;
}

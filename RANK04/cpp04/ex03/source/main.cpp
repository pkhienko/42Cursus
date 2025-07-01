#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main( void )
{
	std::cout << RED "-------------------- Subject Test --------------------" RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmpMat1;
	tmpMat1 = src->createMateria("ice");
	me->equip(tmpMat1);
	delete tmpMat1;

	tmpMat1 = src->createMateria("cure");
	me->equip(tmpMat1);
	delete tmpMat1;

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	std::cout << RED "------------------------------------------------------\n" RESET << std::endl;

	std::cout << RED "-------------------- Additional Test --------------------" RESET << std::endl;
	std::cout << GREEN "---------- Character Test ----------" RESET << std::endl;
	IMateriaSource	*matSrc = new MateriaSource();
	matSrc->learnMateria(new Ice());
	matSrc->learnMateria(new Ice());
	matSrc->learnMateria(new Cure());
	matSrc->learnMateria(new Cure());

	AMateria	*mat = new Cure();
	matSrc->learnMateria(mat);
	delete mat;
	std::cout << GREEN "------------------------------------\n" RESET << std::endl;


	std::cout << GREEN "---------- Character Test ----------" RESET << std::endl;
	std::cout << GREEN "-> Deep copy" << std::endl;
	Character	*a = new Character("A");
	ICharacter	*b = new Character(*a);

	a->use(0, *b);
	b->use(-99, *a);

	delete a;
	delete b;
	std::cout << std::endl;

	ICharacter	*c = new Character("C");
	ICharacter	*d = new Character("D");
	AMateria	*cure = new Cure();
	AMateria	*ice = new Ice();
	AMateria	*tmpMat2;

	tmpMat2 = matSrc->createMateria("ice");
	c->equip(tmpMat2);
	delete tmpMat2;

	tmpMat2 = matSrc->createMateria("cure");
	d->equip(tmpMat2);
	delete tmpMat2;

	tmpMat2 = matSrc->createMateria("bambi ka yee kai jeaw");
	d->equip(tmpMat2); // tmpMat2 return 0
	std::cout << std::endl;

	delete matSrc;

	std::cout << GREEN " -> Test equip" RESET << std::endl;
	c->equip(cure);
	c->equip(ice);
	d->equip(cure);
	d->equip(ice);
	std::cout << std::endl;

	std::cout << GREEN " -> Test unequip" RESET << std::endl;
	c->unequip(0);
	d->unequip(2);
	d->unequip(100);
	std::cout << std::endl;

	delete tmpMat2;
	delete ice;
	delete cure;

	ICharacter	*bambi_ka_yee_kai_jeaw = new Character("bambi_ka_yee_kai_jeaw");

	std::cout << GREEN " -> Test use" RESET << std::endl;
	c->use(0, *bambi_ka_yee_kai_jeaw);
	c->use(2, *bambi_ka_yee_kai_jeaw);
	d->use(4, *bambi_ka_yee_kai_jeaw);
	d->use(1, *bambi_ka_yee_kai_jeaw);
	d->use(-34, *bambi_ka_yee_kai_jeaw);

	delete c;
	delete d;
	delete bambi_ka_yee_kai_jeaw;
	std::cout << RED "------------------------------------------------------" RESET << std::endl;

	return 0;
}

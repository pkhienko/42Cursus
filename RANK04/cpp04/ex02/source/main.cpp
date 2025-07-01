#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

# define NB_ANIMAL 4

int main( void )
{
	const Animal	*animal[NB_ANIMAL];

	std::cout << BLUE "--------------- " MAGENTA "Constructor" BLUE " ---------------" RESET << std::endl;
	for (int i = 0; i < NB_ANIMAL; i++)
	{
		if (i < NB_ANIMAL / 2)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}
	for (int i = 0; i < NB_ANIMAL; i++)
	{
		std::cout << MAGENTA "Animal Type: " YELLOW << animal[i]->getType() << RESET << std::endl;
		animal[i]->makeSound();
		std::cout << std::endl;
	}
	for (int i = 0; i < NB_ANIMAL; i++)
		delete animal[i];
	std::cout << BLUE "------------------------------------------\n" RESET << std::endl;

	std::cout << BLUE "--------------- " MAGENTA "Deep Copy Dog" BLUE " ---------------" RESET << std::endl;
	{

		Dog	*a = new Dog();

		std::cout << MAGENTA "Animal Type: " YELLOW << a->getType() << RESET << std::endl;
		a->makeSound();
		a->getIdea(46);
		a->setIdea("I have to chase it.", 46);
		a->getIdea(46);
		a->getIdea(-1);
		std::cout << std::endl;

		Dog *b = new Dog(*a);
		b->makeSound();
		b->getIdea(46);
		b->getIdea(7);
		std::cout << std::endl;

		delete a;
		delete b;
	}
	std::cout << BLUE "------------------------------------------\n" RESET << std::endl;

	std::cout << BLUE "--------------- " MAGENTA "Deep Copy Cat" BLUE " ---------------" RESET << std::endl;
	{
		Cat	*a = new Cat();

		std::cout << MAGENTA "Animal Type: " YELLOW << a->getType() << RESET << std::endl;
		a->makeSound();
		a->getIdea(99);
		a->setIdea("I have to chase it.", 46);
		a->getIdea(99);
		std::cout << std::endl;

		Cat *b = new Cat(*a);
		std::cout << MAGENTA "Animal Type: " YELLOW << a->getType() << RESET << std::endl;
		b->makeSound();
		b->getIdea(99);
		b->getIdea(2);
		std::cout << std::endl;

		delete a;
		delete b;
	}
	std::cout << BLUE "------------------------------------------\n" RESET << std::endl;

	// Animal *ad = new Animal();
	// ad->makeSound();
	return (0);
}

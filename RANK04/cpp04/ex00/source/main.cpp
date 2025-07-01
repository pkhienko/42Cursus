#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{
	const Animal		*animal = new Animal();
	const Animal		*dog = new Dog();
	const Animal		*cat = new Cat();
	const WrongAnimal	*wrongAnimal = new WrongAnimal();
	const WrongAnimal	*wrongAniCat = new WrongCat();
	const WrongCat		*wrongCat = new WrongCat();
	// WrongAnimal		*wrongAniCat = new WrongCat();
	// const WrongCat	*Cat = static_cast<WrongCat*>(wrongAniCat);

	std::cout << GREEN "----------------------------------------" RESET << std::endl;
	std::cout << MAGENTA "Animal Type: " YELLOW << animal->getType() << RESET << std::endl;
	animal->makeSound();
	std::cout << std::endl;

	std::cout << MAGENTA "Animal Type: " YELLOW << dog->getType() << RESET << std::endl;
	dog->makeSound();
	std::cout << std::endl;

	std::cout << MAGENTA "Animal Type: " YELLOW << cat->getType() << RESET << std::endl;
	cat->makeSound();
	std::cout << std::endl;

	std::cout << MAGENTA "Animal Type: " YELLOW << wrongAnimal->getType() << RESET << std::endl;
	wrongAnimal->makeSound();
	std::cout << std::endl;

	std::cout << MAGENTA "Animal Type: " YELLOW << wrongAniCat->getType() << RESET << std::endl;
	wrongAniCat->makeSound();
	std::cout << std::endl;

	std::cout << MAGENTA "Animal Type: " YELLOW << wrongCat->getType() << RESET << std::endl;
	wrongCat->makeSound();
	std::cout << GREEN "----------------------------------------" RESET << std::endl;
	std::cout << std::endl;

	delete animal;
	delete dog;
	delete cat;
	delete wrongAnimal;
	delete wrongAniCat;
	delete wrongCat;
	// delete Cat;
	return (0);
}

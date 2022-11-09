#include "Animal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"
#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"

int main()
{	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl << std::endl;
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	meta->makeSound();
	std::cout << std::endl;
	delete(meta);
	delete(j);
	delete(i);
	std::cout << std::endl;
	const WrongAnimal* wronganimal = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();
	std::cout << wrongcat->getType() << " " << std::endl;
	std::cout << wronganimal->getType() << " " << std::endl << std::endl;
	wrongcat->makeSound(); //will output the Wrongcat sound!
	wronganimal->makeSound();
	std::cout << std::endl;
	delete(wronganimal);
	delete(wrongcat);
	return (0);
}
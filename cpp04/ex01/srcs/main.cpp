#include "Animal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"
#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"
#include "Brain.class.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	std::cout << std::endl;
	Animal* meta[10];
	for (int i = 0; i < 5; i++){
		meta[i] = new Cat();
	}
	for (int i = 5; i < 10; i++){
		meta[i] = new Dog();
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++){
		meta[i]->makeSound();
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++){
		delete meta[i];
	}
	std::cout << std::endl;
	Animal *meta2 = new Animal[3];
	delete [] meta2;
	return (0);
}
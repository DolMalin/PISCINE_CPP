#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{
		std::cout << "=============================" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->type() << " " << std::endl;
		std::cout << i->type() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	{
		std::cout << "=============================" << std::endl;
		const WrongAnimal* i = new WrongCat();

		std::cout << i->type() << " " << std::endl;
		i->makeSound();

		delete i;	
	}

}
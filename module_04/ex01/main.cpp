#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{
		std::cout << "=============================" << std::endl;
		std::cout << "CONSTRUCTORS" << std::endl;
		std::cout << "=============================" << std::endl;
		
		Cat cat1;
		cat1.brain()->idea(0, "Eat some pasta");
		Cat cat2(cat1);

		std::cout << std::endl << "=============================" << std::endl;
		std::cout << "ACTION" << std::endl;
		std::cout << "=============================" << std::endl;

		std::cout << "cat1: brain.idea[0]: " << cat1.brain()->idea(0) << std::endl;
		std::cout << "cat2: brain.idea[0]: " << cat2.brain()->idea(0) << std::endl;

		cat1.brain()->idea(0, "Destroy humankind");

		std::cout << "cat1: brain.idea[0]: " << cat1.brain()->idea(0) << std::endl;
		std::cout << "cat2: brain.idea[0]: " << cat2.brain()->idea(0) << std::endl;

		std::cout << std::endl << "=============================" << std::endl;
		std::cout << "DESTRUCTORS" << std::endl;
		std::cout << "=============================" << std::endl;
	}


	{
		std::cout << "=============================" << std::endl;
		std::cout << "CONSTRUCTORS" << std::endl;
		std::cout << "=============================" << std::endl;
		
		Dog dog1;
		dog1.brain()->idea(0, "Be a good boy!");
		Dog dog2(dog1);

		std::cout << std::endl << "=============================" << std::endl;
		std::cout << "ACTION" << std::endl;
		std::cout << "=============================" << std::endl;

		std::cout << "dog1: brain.idea[0]: " << dog1.brain()->idea(0) << std::endl;
		std::cout << "dog2: brain.idea[0]: " << dog2.brain()->idea(0) << std::endl;

		dog1.brain()->idea(0, "Smells some dog's butt !");

		std::cout << "dog1: brain.idea[0]: " << dog1.brain()->idea(0) << std::endl;
		std::cout << "dog2: brain.idea[0]: " << dog2.brain()->idea(0) << std::endl;

		std::cout << std::endl << "=============================" << std::endl;
		std::cout << "DESTRUCTORS" << std::endl;
		std::cout << "=============================" << std::endl;		
	}

	
	{
		std::cout << "=============================" << std::endl;
		std::cout << "CONSTRUCTORS" << std::endl;
		std::cout << "=============================" << std::endl;
		
		int n = 10;
		Animal *array[n];

		for (int i = 0; i < n; i++)
		{
			if (i < n / 2)
				array[i] = new Dog();
			else
				array[i] = new Cat();
		}

		std::cout << std::endl << "=============================" << std::endl;
		std::cout << "DESTRUCTORS" << std::endl;
		std::cout << "=============================" << std::endl;			
		for (int i = 0; i < n; i++)
			delete array[i];

	}

}
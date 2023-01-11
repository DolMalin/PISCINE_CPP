#pragma once

#include <string>
#include <iostream>

# define ANIMAL_COLOR "\x1B[36m"
# define DOG_COLOR "\x1B[35m"
# define CAT_COLOR "\x1B[32m"
# define END "\033[0m"

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal &src);
		Animal & operator = (const Animal &rhs);

		std::string	type() const;
		virtual void makeSound() const = 0;

};
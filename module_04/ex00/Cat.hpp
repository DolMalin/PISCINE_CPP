#pragma once

#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat &src);
		Cat & operator = (const Cat &rhs);

		void makeSound() const;
};
#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain *_brain;

	public:
		Cat();
		~Cat();
		Cat(const Cat &src);
		Cat & operator = (const Cat &rhs);

		void makeSound() const;
		Brain	*brain() const;
};
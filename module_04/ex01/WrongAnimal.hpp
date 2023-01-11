#pragma once

#include <string>
#include <iostream>

# define WRONG_ANIMAL_COLOR "\x1B[34m"
# define WRONG_CAT_COLOR "\x1B[35m"
# define END "\033[0m"

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal &src);
		WrongAnimal & operator = (const WrongAnimal &rhs);

		std::string	type() const;
		void makeSound() const;
};
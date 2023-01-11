#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("undefined")
{
	std::cout << WRONG_ANIMAL_COLOR << "[WrongAnimal]: Default constructor called" << END << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << WRONG_ANIMAL_COLOR << "[WrongAnimal]: Destructor called" << END << std::endl;
}


WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << WRONG_ANIMAL_COLOR << "[WrongAnimal]: Copy constructor called" << END << std::endl;
	*this = src;
}


WrongAnimal &WrongAnimal::operator = (const WrongAnimal &rhs)
{
	std::cout << WRONG_ANIMAL_COLOR << "[WrongAnimal]: Copy assignment constructor called" << END << std::endl;
	_type = rhs._type;
	return *this;
}


std::string WrongAnimal::type() const
{
	return _type;
}


void WrongAnimal::makeSound() const
{
	std::cout << WRONG_ANIMAL_COLOR << "AaaaaAaaaaaaaaaaaaaAaaH!" << END << std::endl;
}
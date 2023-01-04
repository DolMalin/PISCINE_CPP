#include "Animal.hpp"

Animal::Animal(): _type("undefined")
{
	std::cout << ANIMAL_COLOR << "[Animal]: Default constructor called" << END << std::endl;
}

Animal::~Animal()
{
	std::cout << ANIMAL_COLOR << "[Animal]: Destructor called" << END << std::endl;
}


Animal::Animal(const Animal &src)
{
	std::cout << ANIMAL_COLOR << "[Animal]: Copy constructor called" << END << std::endl;
	*this = src;
}


Animal &Animal::operator = (const Animal &rhs)
{
	std::cout << ANIMAL_COLOR << "[Animal]: Copy assignment constructor called" << END << std::endl;
	_type = rhs._type;
	return *this;
}


std::string Animal::type() const
{
	return _type;
}


void Animal::makeSound() const
{
	std::cout << ANIMAL_COLOR << "Iä! Cthulhu fhtagn!" << END << std::endl;
}
#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << CAT_COLOR << "[Cat]: Default constructor called" << END << std::endl;
	_type = "Cat";
}


Cat::~Cat()
{
	std::cout << CAT_COLOR << "[Cat]: Destructor called" << END << std::endl;
}


Cat::Cat(const Cat &src): Animal(src)
{
	std::cout << CAT_COLOR << "[Cat]: Copy constructor called" << END << std::endl;
	*this = src;
}


Cat &Cat::operator = (const Cat &rhs)
{
	std::cout << CAT_COLOR << "[Cat]: Copy assignment constructor called" << END << std::endl;
	_type = rhs._type;
	return *this;
}


void Cat::makeSound() const
{
	std::cout << CAT_COLOR << "Meow!" << END << std::endl;
}
#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << CAT_COLOR << "[Cat]: Default constructor called" << END << std::endl;
	_type = "Cat";
	_brain = new Brain();
}


Cat::~Cat()
{
	std::cout << CAT_COLOR << "[Cat]: Destructor called" << END << std::endl;
	delete _brain;
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
	_brain = new Brain();
	for (int i = 0; i < 100; i++)
		_brain->idea(i, rhs.brain()->idea(i));
	return *this;
}


void Cat::makeSound() const
{
	std::cout << CAT_COLOR << "Meow!" << END << std::endl;
}


Brain *Cat::brain() const 
{
	return _brain;
}
#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << DOG_COLOR << "[Dog]: Default constructor called" << END << std::endl;
	_type = "Dog";

}


Dog::~Dog()
{
	std::cout << DOG_COLOR <<  "[Dog]: Destructor called" << END << std::endl;
}


Dog::Dog(const Dog &src): Animal(src)
{
	std::cout << DOG_COLOR << "[Dog]: Copy constructor called" << END << std::endl;
	*this = src; 
}


Dog &Dog::operator = (const Dog &rhs)
{
	std::cout << DOG_COLOR << "[Dog]: Copy assignment constructor called" << END << std::endl;
	_type = rhs._type;
	return *this;
}


void Dog::makeSound() const
{
	std::cout << DOG_COLOR << "Woof!" << END <<std::endl;
}
#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << WRONG_CAT_COLOR << "[WrongCat]: Default constructor called" << END << std::endl;
	_type = "WrongCat";
}


WrongCat::~WrongCat()
{
	std::cout << WRONG_CAT_COLOR << "[WrongCat]: Destructor called" << END << std::endl;
}


WrongCat::WrongCat(const WrongCat &src): WrongAnimal(src)
{
	std::cout << WRONG_CAT_COLOR << "[WrongCat]: Copy constructor called" << END << std::endl;
	*this = src;
}


WrongCat &WrongCat::operator = (const WrongCat &rhs)
{
	std::cout << WRONG_CAT_COLOR << "[WrongCat]: Copy assignment constructor called" << END << std::endl;
	_type = rhs._type;
	return *this;
}


void WrongCat::makeSound() const
{
	std::cout << WRONG_CAT_COLOR << "Meow??????" << END << std::endl;
}
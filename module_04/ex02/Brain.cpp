#include "Brain.hpp"

Brain::Brain()
{
    std::cout << BRAIN_COLOR << "[Brain]: Default constructor called" << END << std::endl;
}


Brain::~Brain()
{
	std::cout << BRAIN_COLOR << "[Brain]: Destructor called" << END << std::endl;

}


Brain::Brain(const Brain &src)
{
	std::cout << BRAIN_COLOR << "[Brain]: Copy constructor called" << END << std::endl;
    *this = src;
}


Brain &Brain::operator = (const Brain &rhs)
{
	std::cout << BRAIN_COLOR << "[Brain]: Copy assignment constructor called" << END << std::endl;
    for (int i = 0; i < 100; i++)
        _ideas[i] = rhs._ideas[i];
    return *this;
}


std::string Brain::idea(int index)
{
    if (index < 0 || index > 99)
        return std::string();
    return _ideas[index];
}


void Brain::idea(int index, std::string value)
{
    if (index < 0 || index > 99)
        return ;
    _ideas[index] = value;
}
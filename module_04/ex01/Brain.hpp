#pragma once

#include <string>
#include <iostream>

# define BRAIN_COLOR "\x1B[34m"
# define END "\033[0m"

class Brain
{
    private:
        std::string _ideas[100];
    public:
        Brain();
        ~Brain();
        Brain(const Brain &src);
        Brain & operator = (const Brain &rhs);

        std::string idea(int index);
        void idea(int index, std::string value);
};
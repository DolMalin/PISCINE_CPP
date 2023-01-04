NAME		= 	a.out

SRCS		= 	main.cpp \
				Animal.cpp \
				WrongAnimal.cpp \
				Dog.cpp \
				Cat.cpp \
				WrongCat.cpp \

OBJ			=	$(SRCS:.cpp=.o)

HEADERS		=	Animal.hpp \
				Dog.hpp \
				Cat.hpp \
				WrongAnimal.hpp \
				WrongCat.hpp

			
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

all:		$(NAME)

%.o:		%.c $(HEADERS) Makefile
			$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME):	$(OBJ) $(HEADERS) Makefile
			$(CXX) -o $(NAME) $(OBJ)

clean:
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean Makefile re
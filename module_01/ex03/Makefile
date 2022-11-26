NAME		= 	a.out

SRCS		= 	main.cpp \
				Weapon.cpp \
				HumanA.cpp \
				HumanB.cpp

OBJ			=	$(SRCS:.cpp=.o)

HEADERS		=	Weapon.hpp \
				HumanA.hpp \
				HumanB.hpp
				
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
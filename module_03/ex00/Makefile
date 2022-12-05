NAME		= 	a.out

SRCS		= 	main.cpp \
				ClapTrap.cpp

OBJ			=	$(SRCS:.cpp=.o)

HEADERS		=	ClapTrap.hpp
			
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
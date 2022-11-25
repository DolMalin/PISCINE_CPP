NAME		= 	a.out

SRCS		= 	main.cpp \
				Zombie.cpp \
				newZombie.cpp \
				randomChump.cpp

OBJ			=	$(SRCS:.cpp=.o)

HEADERS		=	srcs/Zombie.hpp
				
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

all:		$(NAME)

%.o:		%.c $(HEADERS) Makefile
			$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME):	$(OBJ)
			$(CXX) -o $(NAME) $(OBJ)
			
clean:		
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
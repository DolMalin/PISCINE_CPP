NAME		= 	a.out

SRCS		= 	main.cpp

OBJ			=	$(SRCS:.cpp=.o)
				
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

all:		$(NAME)

%.o:		%.c Makefile
			$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME):	$(OBJ) Makefile
			$(CXX) -o $(NAME) $(OBJ)
			
clean:		
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean Makefile re
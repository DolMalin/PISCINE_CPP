# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 14:47:24 by pdal-mol          #+#    #+#              #
#    Updated: 2022/11/24 22:00:24 by pdal-mol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	account_tests

SRCS		= 	Account.cpp\
				tests.cpp

OBJ			=	$(SRCS:.cpp=.o)

HEADERS		=	srcs/Account.hpp
				
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
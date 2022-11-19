# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 14:47:24 by pdal-mol          #+#    #+#              #
#    Updated: 2022/11/19 22:23:50 by pdal-mol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	awesome_phonebook

SRCS		= 	srcs/main.cpp\
				srcs/Contact.cpp\
				srcs/PhoneBook.cpp

OBJ			=	$(SRCS:.cpp=.o)

HEADERS		=	srcs/Contact.hpp\
				srcs/PhoneBook.hpp
				
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
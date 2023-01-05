# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdal-mol <pdal-mol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 14:47:24 by pdal-mol          #+#    #+#              #
#    Updated: 2023/01/05 10:42:45 by pdal-mol         ###   ########.fr        #
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

$(NAME):	$(OBJ) $(HEADERS) Makefile
			$(CXX) -o $(NAME) $(OBJ)
			
clean:		
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean Makefile re
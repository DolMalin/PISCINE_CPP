# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdal-mol <pdal-mol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 12:52:28 by pdal-mol          #+#    #+#              #
#    Updated: 2023/01/06 10:49:20 by pdal-mol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= megaphone

SRC			= megaphone.cpp
OBJ			= megaphone.o 

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

all:		$(NAME)

%.o:		%.cpp 
			$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME):	$(OBJ) Makefile
			$(CXX) -o $(NAME) $(OBJ)
			
clean:		
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
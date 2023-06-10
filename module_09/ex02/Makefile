# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 12:00:23 by pdal-mol          #+#    #+#              #
#    Updated: 2023/06/08 16:43:05 by pdal-mol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= 	PmergeMe
CXX				=	c++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98 -MD

INCLUDES		=	PmergeMe.hpp

LST_SRCS		=	main.cpp \
					PmergeMe.cpp
					
LST_OBJ			=	$(LST_SRCS:.cpp=.o)
OBJ				=	$(addprefix .objects/,$(LST_OBJ))
DEP				=	$(OBJ:.o=.d)


all:			$(NAME)

.objects/%.o: 	%.cpp $(INCLUDES) Makefile | .objects
				$(CXX) $(CXXFLAGS) -c $< -o $@

.objects:
	mkdir -p '.objects'

$(NAME):		$(OBJ)
				$(CXX) -o $(NAME) $(OBJ)
			
clean:		
				rm -rf $(OBJ) $(DEP)

fclean:			clean
				rm -rf $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re

-include 		$(DEP)
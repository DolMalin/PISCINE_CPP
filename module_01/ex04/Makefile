# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdal-mol <pdal-mol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 11:43:22 by pdal-mol          #+#    #+#              #
#    Updated: 2023/01/06 11:43:25 by pdal-mol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 	sed
CXX				=	c++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98 -MD

LST_SRCS		= 	main.cpp
					
LST_OBJ			=	$(LST_SRCS:.cpp=.o)
OBJ				=	$(addprefix .objects/,$(LST_OBJ))
DEP				=	$(OBJ:.o=.d)

all:			$(NAME)

.objects/%.o: 	%.cpp | .objects
				$(CXX) $(CXXFLAGS) -c $< -o $@ 

$(NAME):		$(OBJ) Makefile
				$(CXX) -o $(NAME) $(OBJ)

.objects:
	mkdir -p '.objects'
			
clean:		
				rm -rf $(OBJ) $(DEP)

fclean:			clean
				rm -rf $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean Makefile re

-include 		$(DEP)
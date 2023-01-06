# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdal-mol <pdal-mol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 15:45:30 by pdal-mol          #+#    #+#              #
#    Updated: 2023/01/06 15:45:36 by pdal-mol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= 	bsp
CXX				=	c++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98 -MD

INCLUDES		=	Fixed.hpp \
					Point.hpp

LST_SRCS		= 	main.cpp \
					Fixed.cpp \
					Point.cpp \
					bsp.cpp
					
LST_OBJ			=	$(LST_SRCS:.cpp=.o)
OBJ				=	$(addprefix .objects/,$(LST_OBJ))
DEP				=	$(OBJ:.o=.d)


all:			$(NAME)

.objects/%.o: 	%.cpp $(HEADERS)| .objects
				$(CXX) $(CXXFLAGS) -c $< -o $@ $(HEADERS)

.objects:
	mkdir -p '.objects'

$(NAME):		$(OBJ) Makefile
				$(CXX) -o $(NAME) $(OBJ)
			
clean:		
				rm -rf $(OBJ) $(DEP)

fclean:			clean
				rm -rf $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean Makefile re

-include 		$(DEP)
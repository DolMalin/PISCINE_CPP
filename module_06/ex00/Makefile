# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 10:21:49 by pdal-mol          #+#    #+#              #
#    Updated: 2023/01/17 15:22:19 by pdal-mol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= 	scalar
CXX				=	c++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98 -MD #-fsanitize=address

INCLUDES		=	Scalar.hpp

LST_SRCS		=	main.cpp \
					Scalar.cpp
					
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
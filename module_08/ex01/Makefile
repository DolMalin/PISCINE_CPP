# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdal-mol <pdal-mol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 10:21:49 by pdal-mol          #+#    #+#              #
#    Updated: 2023/01/24 10:55:32 by pdal-mol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= 	span
CXX				=	c++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98 -MD

INCLUDES		=	Span.hpp

LST_SRCS		=	main.cpp \
					Span.cpp
					
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
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 12:00:23 by pdal-mol          #+#    #+#              #
#    Updated: 2023/04/18 14:50:03 by pdal-mol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= 	btc
CXX				=	c++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98 -MD

INCLUDES		=	BitcoinExchange.hpp

LST_SRCS		=	main.cpp \
					BitcoinExchange.cpp
					
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
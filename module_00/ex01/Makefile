# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdal-mol <pdal-mol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 14:47:24 by pdal-mol          #+#    #+#              #
#    Updated: 2023/01/06 10:48:06 by pdal-mol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 	account_tests
CXX				=	c++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98 -MD

INCLUDES		=	Contact.hpp\
					PhoneBook.hpp

LST_SRCS		= 	main.cpp\
					Contact.cpp\
					PhoneBook.cpp
					
LST_OBJ			=	$(LST_SRCS:.cpp=.o)
OBJ				=	$(addprefix .objects/,$(LST_OBJ))
DEP				=	$(OBJ:.o=.d)



all:			$(NAME)

.objects/%.o: 	%.cpp $(HEADERS)| .objects
				$(CXX) $(CXXFLAGS) -c $< -o $@ $(HEADERS)

$(NAME):		$(OBJ) Makefile
				$(CXX) -o $(NAME) $(OBJ)
			
clean:		
				rm -rf $(OBJ) $(DEP)

fclean:			clean
				rm -rf $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean Makefile re

-include 		$(DEP)

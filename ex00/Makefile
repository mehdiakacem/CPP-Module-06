# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makacem <makacem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/07 15:14:41 by makacem           #+#    #+#              #
#    Updated: 2023/06/11 10:11:11 by makacem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98
HEADER = ScalarConverter.hpp

SRC = main.cpp ScalarConverter.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS)  $(OBJ) -o $(NAME)

%.o : %.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makacem <makacem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/11 10:31:27 by makacem           #+#    #+#              #
#    Updated: 2023/06/11 12:38:08 by makacem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serialize

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98
HEADER = Serializer.hpp

SRC = main.cpp Serializer.cpp

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
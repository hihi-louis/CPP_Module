# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/16 18:20:14 by tripham           #+#    #+#              #
#    Updated: 2025/06/16 18:26:14 by tripham          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= Account
CC		:= c++
FLAGS	:= -Wall -Wextra -Werror -std=c++98
SRCS	:= tests.cpp Account.cpp
OBJ		:= $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	
%.o : %.cpp
		$(CC) $(FLAGS) -c $< -o $@

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
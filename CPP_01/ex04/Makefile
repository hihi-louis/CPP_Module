# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/27 02:05:16 by tripham           #+#    #+#              #
#    Updated: 2025/07/09 04:31:49 by tripham          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	Replace
CC		:=	c++
FLAGS	:=	-Wall -Wextra -Werror -std=c++98
SRC		:=	main.cpp ex04.cpp
OBJ		:= $(SRC:.cpp=.o)

GREEN	:= \033[0;32m
BLUE	:= \033[0;34m
RESET	:= \033[0m

all : $(NAME)

%.o : %.cpp
		@$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
		@echo "$(GREEN)Success$(RESET)"
		@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean: 
	@rm -rf $(OBJ)

fclean: clean
		@echo "$(BLUE)Cleanning Success$(RESET)"
		@rm -rf $(NAME)
		
re: fclean all

.PHONY: all clean fclean re
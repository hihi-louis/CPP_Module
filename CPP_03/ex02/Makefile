# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/05 14:32:51 by tripham           #+#    #+#              #
#    Updated: 2025/07/09 04:30:33 by tripham          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	FragTrap
CC		:=	c++
FLAGS	:=	-Wall -Wextra -Werror -std=c++20
SRC		:=	main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
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
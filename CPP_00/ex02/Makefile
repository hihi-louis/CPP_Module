# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/16 18:20:14 by tripham           #+#    #+#              #
#    Updated: 2025/06/16 18:37:53 by tripham          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= Account
CC		:= c++
FLAGS	:= -Wall -Wextra -Werror -std=c++98
SRCS	:= tests.cpp Account.cpp
OBJ		:= $(SRCS:.cpp=.o)

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
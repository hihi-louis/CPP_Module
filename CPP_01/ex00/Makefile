# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 18:00:05 by tripham           #+#    #+#              #
#    Updated: 2025/07/12 13:50:14 by tripham          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= TrainToBusan
CC		:= c++
FLAGS	:= -Wall -Wextra -Werror -std=c++20
SRCS	:= main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
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
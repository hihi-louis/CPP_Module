# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/08 22:50:30 by tripham           #+#    #+#              #
#    Updated: 2025/06/16 18:38:55 by tripham          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
SRC  = megaphone.cpp
OBJ  = $(SRC:.cpp=.o)
RM	 = rm -rf
CC   = c++
FLAGS = -Wall -Wextra -Werror -std=c++20

GREEN	:= \033[0;32m
BLUE	:= \033[0;34m
RESET	:= \033[0m

all: $(NAME)

%.o : %.cpp
		@$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
		@echo "$(GREEN)Success$(RESET)"
		@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
		@$(RM) $(OBJ)
fclean:	clean
		@echo "$(BLUE)Cleanning Success$(RESET)"
		@$(RM) $(NAME)

re:		fclean all
.PHONY: all clean fclean re

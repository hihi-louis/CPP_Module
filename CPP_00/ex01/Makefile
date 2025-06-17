# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/15 15:07:42 by tripham           #+#    #+#              #
#    Updated: 2025/06/16 18:38:31 by tripham          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= phonebook
FLAGS 	:= -Wall -Wextra -Werror -std=c++20
SRCS		:=	Contact.cpp		\
				PhoneBook.cpp	\
				main.cpp
OBJ		:=	$(SRCS:.cpp=.o)
RM 		:=	rm -rf
CC		:= c++

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
fclean: clean
		@echo "$(BLUE)Cleanning Success$(RESET)"
		@$(RM) $(NAME)
re:		fclean all
.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/15 15:07:42 by tripham           #+#    #+#              #
#    Updated: 2025/06/15 16:00:46 by tripham          ###   ########.fr        #
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

all: $(NAME)

%.o : %.cpp
		@$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
		@echo "Success"
		@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
		@$(RM) $(OBJ)
fclean: clean
		@echo "Cleanning Success"
		@$(RM) $(NAME)
re:		fclean all
.PHONY: all clean fclean re
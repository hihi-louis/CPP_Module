# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/08 22:50:30 by tripham           #+#    #+#              #
#    Updated: 2025/06/08 22:51:10 by tripham          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
SRC  = megaphone.cpp
OBJ  = $(SRC:.cpp=.o)
RM	 = rm -rf
CC   = c++
FLAGS = -Wall -Wextra -Werror -std=c++20

all: $(NAME)

%.o : %.cpp
		@$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
		@echo "Success"
		@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
		@$(RM) $(OBJ)
fclean:	clean
		@echo "Cleanning Success"
		@$(RM) $(NAME)

re:		fclean all
.PHONY: all clean fclean re

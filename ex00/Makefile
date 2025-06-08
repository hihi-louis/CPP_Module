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

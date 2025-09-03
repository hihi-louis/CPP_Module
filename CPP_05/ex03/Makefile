NAME	:=	SignForm
CC		:=	c++
FLAGS	:=	-Wall -Wextra -Werror -std=c++20
SRC		:=	main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp Intern.cpp
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
		@echo "Removing shrubbery files..."
		@find . -name '*_shrubbery' -print -delete
		@rm -rf $(NAME)
		@echo "$(BLUE)Cleanning Success$(RESET)"

re: fclean all

.PHONY: all clean fclean re
#pragma once

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

# define INFO(msg)		std::cout << CYAN << msg << RESET << std::endl
# define SUCCESS(msg)	std::cout << GREEN << msg << RESET << std::endl
# define ERROR_MSG(msg)	std::cout << RED << msg << RESET << std::endl
# define WARNING(msg)	std::cout << YELLOW << msg << RESET << std::endl
# define TITLE(msg)		std::cout << BLUE << msg << RESET << std::endl
# define EXCEPTION(msg) std::cout << MAGENTA << msg << RESET << std::endl
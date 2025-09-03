#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <string>
#include <new>
#include <cstdlib> // for rand()
#include <ctime>   // for time()
#include <fstream>  // for std::ofstream
#include <stdexcept> // for std::runtime_error

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
# define EXCEPTION(msg)	std::cout << YELLOW << msg << RESET << std::endl
# define TITLE(msg)		std::cout << BLUE << msg << RESET << std::endl
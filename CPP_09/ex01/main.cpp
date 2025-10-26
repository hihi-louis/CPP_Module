#include "RPN.hpp"

int main(int argc, char **argv){
	if (argc != 2)
	{
		std::cerr << CYAN << "Invalid input" << RESET << std::endl;
		return 1;
	}
	try{
		double result = RPN::calculate(argv[1]);
		std::cout << GREEN <<result << RESET  << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		return 1;
	}
	return 0;
}
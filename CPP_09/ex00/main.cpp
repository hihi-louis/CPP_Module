#include "BitcoinExchange.hpp"

int main(int argc, char** argv){
	if (argc != 2 ) {
		std::cout << CYAN << "Invalid input" << RESET << std::endl;
		std::cout << CYAN << "Usage: ./btc <input_file>" << RESET << std::endl;
		return 1;
	}

	try {
		BitcoinExchange btc("data.csv");
		btc.processInputFile(argv[1]);
	}catch (std::exception &e){
		std::cout << YELLOW << e.what() << RESET << std::endl;
		return 1;
	}
	return 0;
}
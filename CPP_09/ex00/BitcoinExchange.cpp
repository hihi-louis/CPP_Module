#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string_view dataBasePath)
{
	_loadDataBase(dataBasePath);
}

void BitcoinExchange::_loadDataBase(std::string_view dataBasePath)
{
	std::ifstream dbFile(dataBasePath.data());
	if (!dbFile.is_open())
		throw std::runtime_error("Error: Could not open database file.");
	std::string line;
	// Skip header line
	if (!std::getline(dbFile, line))
		throw std::runtime_error("Error: Database is empty or unreadable.");
	while (std::getline(dbFile, line))
	{
		std::stringstream ss(line);
		std::string dateString;
		std::string priceStr;

		if (std::getline(ss, dateString, ',') && std::getline(ss, priceStr))
		{
			try
			{
				size_t pos;
				double price = std::stod(priceStr, &pos);
				if (pos != priceStr.length())
				{
					continue;
				}
				this->_dataBase[dateString] = price;
			}catch (const std::invalid_argument& e){
				std::cout << "Warning: Invalid Price format in database: " << priceStr << std::endl;
			}catch (const std::out_of_range& e){
				std::cout << "Warning: Price out of range in database: " << priceStr << std::endl;
			}
		}
	}	
}

void BitcoinExchange::processInputFile(std::string_view inputFilePath) const

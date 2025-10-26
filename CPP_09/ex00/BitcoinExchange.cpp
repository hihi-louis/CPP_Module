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
				std::cout << YELLOW << "Warning: Invalid Price format in database: " << priceStr << std::endl;
			}catch (const std::out_of_range& e){
				std::cout << YELLOW << "Warning: Price out of range in database: " << priceStr << std::endl;
			}
		}
	}	
}

void BitcoinExchange::processInputFile(std::string_view inputFilePath) const
{
	std::ifstream inputFile(inputFilePath.data());
	if (!inputFile.is_open())
		throw std::runtime_error("Error: Could not open input file.");
	std::string line;
	// Skip header line
	if (!std::getline(inputFile, line))
		throw std::runtime_error("Error: Input file is empty or unreadable.");
	while (std::getline(inputFile, line))
	{
		try
		{
			std::stringstream ss(line);
			std::string dateStr;
            std::string priceStr;
			char deli;
			if (line.empty())
				throw std::runtime_error("Error: Bad input because of new line");

			if (!(ss >> dateStr >> deli >> priceStr) || deli != '|') {
                throw std::runtime_error("Error: Bad input => " + line);
            }

			std::string junk;
            if (ss >> junk) {
                throw std::runtime_error("Error: Bad input => " + line);
            }

			_validateDate(dateStr);
			double value = _validateValue(priceStr);

			_findAndPrint(dateStr, value);
		}
		catch(const std::exception& e)
		{
			std::cout << RED << e.what() << '\n' << RESET;
		}
	}
}

void BitcoinExchange::_validateDate(std::string_view dateStr){
	std::stringstream ss(dateStr.data());
	char deli1, deli2;
	int y_val, d_val, m_val;
	if (!(ss >> y_val >> deli1 >> m_val >> deli2 >> d_val) || deli1 != '-' || deli2 != '-'){
		throw std::runtime_error("Error: Wrong date format => " + std::string(dateStr));
	}
	std::string junk;
    if (ss >> junk) {
        throw std::runtime_error("Error: Bad date format (trailing chars) => " + std::string(dateStr));
    }
	std::chrono::year y = std::chrono::year{y_val};
	auto m = std::chrono::month{static_cast<unsigned int>(m_val)};
	auto d = std::chrono::day{static_cast<unsigned int>(d_val)};
	std::chrono::year_month_day dateToCheck(y, m, d);
	if (!dateToCheck.ok())
		throw std::runtime_error("Error: Invalid date logic => " + std::string(dateStr));
}

double BitcoinExchange::_validateValue(std::string_view valueStr){
	double value;
	try
	{
		size_t pos;
		value = std::stod(std::string(valueStr), &pos);
		if (pos != valueStr.length())
			throw std::runtime_error("Error: Invalid price format => " + std::string(valueStr));
	}
	catch(const std::exception& e)
	{
		throw;
	}
	if (value < 0)
		throw std::runtime_error("Error: Negative number: " + std::string(valueStr));

	if (value > 1000) 
		throw std::runtime_error("Error: Too large a number");

	if (value == 1000)
	{
		size_t decimalPos = valueStr.find('.');
		if (decimalPos != std::string_view::npos)
		{
			std::string_view fractionalPart = valueStr.substr(decimalPos + 1);
			if (fractionalPart.find_first_not_of('0') != std::string_view::npos)
			{
				throw std::runtime_error("Error: Too large a number");
			}
		}
	}
	return value;
}

void BitcoinExchange::_findAndPrint(std::string_view date, double value) const{
	//auto <=> std::map<std::string, double>::const_iteration/iteration
	auto it = _dataBase.upper_bound(std::string(date));
	if (it == _dataBase.begin())
		throw std::runtime_error("Warning: No data available for or before date => " + std::string(date));
	it--;
	double exchangeRate = it->second;
	double result = exchangeRate * value;

	std::cout << GREEN << date << " => " << value << " = " << result << RESET << std::endl;
	// std::cout << date << " => " << value << " = " << result << std::endl;
}
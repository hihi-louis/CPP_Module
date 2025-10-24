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
			const std::string deli = "|";
			size_t pos = line.find('|');
			if (pos == std::string::npos)
				throw ("Bad input file: " + line);
			std::string_view dateStr = std::string_view(line).substr(0, pos);
			std::string_view priceStr = std::string_view(line).substr(pos + deli.length());

			_validateDate(dateStr);
			double value = _validateValue(priceStr);

			_findAndPrint(dateStr, value);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

void BitcoinExchange::_validateDate(std::string_view dateStr){
	std::stringstream ss(dateStr.data());
	char deli;
	int y_val, d_val, m_val;

	if (!(ss >> y_val >> deli >> m_val >> deli >> d_val) || deli != '-'){
		throw ("Wrong date format: " + std::string(dateStr));
	}

	std::chrono::year y = std::chrono::year{y_val};
	auto m = std::chrono::month{m_val};
	auto d = std::chrono::day(d_val);
	std::chrono::year_month_day dateToCheck(y, m, d);
	if (!dateToCheck.ok())
		throw ("Invalid date logic: " + std::string(dateStr));
}
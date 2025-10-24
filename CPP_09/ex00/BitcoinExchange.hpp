#pragma once

#include <map>
#include <algorithm>
#include <ctime>
#include <stdexcept>
#include <string_view>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <chrono>
class BitcoinExchange
{
	
	public:
	BitcoinExchange() = default;
	~BitcoinExchange() = default;
	BitcoinExchange(const BitcoinExchange& other) = default;
	BitcoinExchange& operator=(const BitcoinExchange& other) = default;
	
	void			processInputFile(std::string_view inputFilePath) const;
	explicit		BitcoinExchange(std::string_view dataBasePath);

	private:
		std::map<std::string, double> _dataBase;
		
		void			_loadDataBase(std::string_view dataBasePath);
		void			_findAndPrint(std::string_view date, double value) const;

		static void		_validateDate(std::string_view dateStr);
		static double	_validateValue(std::string_view valueStr);
};
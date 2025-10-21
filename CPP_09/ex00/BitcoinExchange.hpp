#pragma once

#include <map>
#include <algorithm>
#include <ctime>
#include <stdexcept>
#include <string_view>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _dataBase;
		
		void			_loadDataBase(std::string_view dataBasePath);
		void			_findAndPrint(std::string_view date, double value) const;

		static void		_validateDate(std::string_view dataStr);
		static double	_validateValue(std::string_view valueStr);

	public:
		BitcoinExchange() = default;
		~BitcoinExchange() = default;
		BitcoinExchange(const BitcoinExchange& other) = default;
		BitcoinExchange& operator=(const BitcoinExchange& other) = default;

		void			processInputFile(std::string_view inputFilePath) const;
		explicit		BitcoinExchange(std::string_view dataBasePath);
};
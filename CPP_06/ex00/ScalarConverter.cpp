#include "ScalarConverter.hpp"

enum stringType{INVALID, CHAR, INT, FLOAT, DOUBLE};

static stringType detectType(const std::string &s)
{
	//1. Psuedo Literal
	if (s == "nanf" || s == "+inff" || s == "-inff")
		return FLOAT;
	if (s == "nan" || s == "+inf" || s == "-inf")
		return DOUBLE;
	
	//2. Single char (non digit)
	if (s.size() == 1 && !std::isdigit(s[0]))
		return CHAR;
	
	//3. Decimal number: float (if ends with 'f') or double
	if (s.find('.') != std::string::npos)
	{
		if (s.back() == 'f') // if s.empty() true -> s.back() will be crashed
			return FLOAT;
		return DOUBLE;
	}

	//4. Interger check
	size_t sign = 0;
	if (s[0] == '+' || s[0] == '-')
		sign = 1;
	if (sign == s.size())
		return INVALID;
	for (size_t i = sign; i < s.size(); i++)
	{
		if (!std::isdigit(s[i]))
			return INVALID;
	}
	return INT;
}



void ScalarConverter::convert(std::string const &s)
{

}
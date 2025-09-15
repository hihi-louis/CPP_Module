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
	stringType type = detectType(s);
	// char cVal = 0;
	// int iVal = 0;
	// float fVal = 0.0f;
	double dVal;

	try
	{
		size_t idx;

		if (type == CHAR)
			dVal = static_cast<double>(s[0]);
		else if (type == INT)
		{	dVal = static_cast<double>(std::stoi(s, &idx));
			if (s.size() != idx)
				throw std::invalid_argument("invalid input");
		}
		else if (type == FLOAT)
		{
			dVal = static_cast<double>(std::stof(s, &idx));
			// if (s.size() != idx && s != "nan" && s != "nanf")
			// 	throw std::invalid_argument("invalid input");
			if (!(idx == s.size() || (idx == s.size() - 1 && s.back() == 'f')))
        		throw std::invalid_argument("invalid input");
		}
		else if (type == DOUBLE)
		{
			dVal = std::stod(s, &idx);
			if (s.size() != idx && s != "nan" && s != "nanf")
				throw std::invalid_argument("invalid input");
		}
		else
		{
			std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
            return;
		}
	}
	catch (...)
	{
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
        return;
	}

	// CHAR
	if (std::isnan(dVal) || std::isinf(dVal) || dVal < std::numeric_limits<char>::min() || dVal > std::numeric_limits<char>::max())
		std::cout << "char: impossible\n";
	else if (std::isprint(static_cast<char>(dVal)))
		std::cout << "char: '" << static_cast<char>(dVal) << "'\n";
	else 
		std::cout << "char: Non displayable\n";
	// INT
	if (std::isnan(dVal) || std::isinf(dVal) || dVal < std::numeric_limits<int>::min() || dVal > std::numeric_limits<int>::max())
		std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(dVal) << "\n";
	// FLOAT
// FLOAT
	float fVal = static_cast<float>(dVal);
	if (std::isnan(fVal))
    	std::cout << "float: nanf\n";
	else if (std::isinf(fVal))
	{
		if (std::signbit(fVal))
			std::cout << "float: -inff\n";
		else
			std::cout << "float: +inff\n";
	}
	else 
		std::cout << std::fixed << std::setprecision(1)<< "float: " << fVal << "f\n";

	// DOUBLE
	if (std::isnan(dVal))
    	std::cout << "double: nan\n";
	else if (std::isinf(dVal))
	{
		if (std::signbit(dVal))
			std::cout << "double: -inf\n";
		else
			std::cout << "double: +inf\n";
	}
	else
		std::cout << std::fixed << std::setprecision(1) << "double: " << dVal << std::endl;
}
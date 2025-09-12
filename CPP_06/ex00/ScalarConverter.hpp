#pragma once

#include <iostream>
#include <iomanip>
#include <limits>
#include <cctype>
#include <cmath>

class ScalarConverter{
    public:
        static void convert(std::string const &s);

        ScalarConverter() = delete;
        ~ScalarConverter() = delete;
        ScalarConverter(const ScalarConverter& other) = delete;
        ScalarConverter& operator=(const ScalarConverter& other) = delete;
};

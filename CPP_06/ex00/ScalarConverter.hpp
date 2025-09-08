#pragma once

#include <iostream>

class ScalarConverter{
    public:
        static void convert(std::string const &literal);

        ScalarConverter() = delete;
        ~ScalarConverter() = delete;
        ScalarConverter(const ScalarConverter& other) = delete;
        ScalarConverter& operator=(const ScalarConverter& other) = delete;
};

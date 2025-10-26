#pragma once

#include <algorithm>
#include <iostream>
#include <math.h>
#include <stack>
#include <sstream>
#include <string>
#include "sys.hpp"

class RPN{
	private:
		RPN() = default;
		~RPN() = default;
		RPN& operator=(const RPN& other) = delete;
		RPN(const RPN& other) = delete;
	public:
		static double calculate(std::string_view av);
};
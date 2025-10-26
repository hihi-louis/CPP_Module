#include "RPN.hpp"

double RPN::calculate(std::string_view av){
	std::stack<double> stack;
	std::stringstream ss(av.data());
	std::string token;
	while (ss >> token)
	{
		// Case: token is an operator
		if (token.length() == 1 && std::string("+-*/").find(token[0]) != std::string::npos)
		{
			
			if (stack.size() < 2)
				throw std::runtime_error("Invalid expression: Insufficient values");
			double rightNum = stack.top(); stack.pop();
			double leftNum = stack.top(); stack.pop();

			switch (token[0])
			{
				case '+': stack.push(leftNum + rightNum); break;
				case '-': stack.push(leftNum - rightNum); break;
				case '*': stack.push(leftNum * rightNum); break;
				case '/':
					if (rightNum == 0)
						throw std::runtime_error("Division by zero");
					stack.push(leftNum / rightNum);
			}
		}
		// Case: process like a number
		else{
				size_t pos;
				double num = std::stod(token, &pos);
				if (pos != token.length())
					throw std::runtime_error("Invalid token");
				if (num > 10)
					throw std::runtime_error("Number > 10");
				stack.push(num);
		}
	}
		if (stack.size() != 1)
			throw std::runtime_error("Invalid Expression");
	return stack.top();
}
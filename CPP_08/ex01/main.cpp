#include "Span.hpp"

int main()
{
	{	try {
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch(const std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	{
		Span sp = Span(5);
		try {
			std::list<int> intList = {1, -2147483648, 2147483647, -10, -42};
			std::vector<int> vec(intList.begin(), intList.end());
			sp.addNumber(vec.begin(), vec.end());
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}catch(const std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
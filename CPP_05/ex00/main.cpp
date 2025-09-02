#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("Harry Portter", 0);
		std::cout << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat A("Harry Portter", 5);
		std::cout << A << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	Bureaucrat b("Doraemon", 149);

	try
	{
		std::cout << b << std::endl;
		b.decrementGrade();
		b.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
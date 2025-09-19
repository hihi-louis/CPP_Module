#include "identify.hpp"

Base* generate(void)
{
	switch (std::rand() % 3)
	{
	case 0:
		std::cout << "Generate: A" << std::endl;
		return (new A);
	case 1:
		std::cout << "Generate: B" << std::endl;
		return (new B);
	default:
		std::cout << "Generate: C" << std::endl;
		return (new C);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else 
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return ;
	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return ;

	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return ;

	}
	catch(const std::exception& e){}
	std::cout << "Unknown type" << std::endl;
}
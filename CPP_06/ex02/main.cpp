#include "identify.hpp"
#include "Base.hpp"

int main()
{
	std::srand(std::time(NULL));
	for (int i = 0; i < 7; i++)
	{
		std::cout << "Test: " << i + 1 << "\n";
		Base *test = nullptr;
		try {
			test = generate();
			std::cout << "Identify ptr: ";
			identify(test);
			std::cout << "Identify ref: ";
			identify(*test);
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		delete test;
		test = nullptr;
		std::cout << std::endl;
	}
	return 0;
}



#include "ShrubberyCreationForm.hpp"

int main()
{
	try {
		ShrubberyCreationForm a("Louis");
		Bureaucrat b("haha", 30);

		a.beSigned(b);

		a.execute(b);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try{
		Robomy
	}
	return 0;
}
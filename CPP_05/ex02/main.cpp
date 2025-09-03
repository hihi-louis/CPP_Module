#include "sys.hpp"

int main()
{
	{
		INFO("*==================== Shrubbery Test ====================*");
		try {
			TITLE("---Create Executor---");
			Bureaucrat daddy("daddy", 150);
			Bureaucrat mommy("mommy", 3);
			std::cout << daddy << std::endl;
			std::cout << mommy << std::endl;
			
			TITLE("---Create ShrubberyCreationForm---");
			ShrubberyCreationForm berryForm("berryForm");
			std::cout << berryForm << std::endl;

			TITLE("---Execute Unsigned Form---");
			daddy.executeForm(berryForm);
			mommy.executeForm(berryForm);

			TITLE("---Sign Form---");
			daddy.signForm(berryForm);
			mommy.signForm(berryForm);
			std::cout << berryForm << std::endl;

			TITLE("---Execute Signed Form---");
			daddy.executeForm(berryForm);
			mommy.executeForm(berryForm);

		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	{
		try {
			std::srand(std::time(nullptr)); // create seed to return the number of second since 1/1/1970 until now, and create difference pseudo-random
			INFO("\n*==================== Robotomy Testing ====================*\n");
			TITLE("---Create Executor---");
				Bureaucrat daddy("daddy", 150);
				Bureaucrat mommy("mommy", 3);
				std::cout << daddy << std::endl;
				std::cout << mommy << std::endl;
			TITLE("\n---Create RobotomyRequestForm---\n");
				RobotomyRequestForm robotForm("RobotForm");
				std::cout << robotForm << std::endl;
			TITLE("\n---Execute Unsigned Form---\n");
				daddy.executeForm(robotForm);
				mommy.executeForm(robotForm);
				std::cout << robotForm << std::endl;
			TITLE("---Sign Form---");
				daddy.signForm(robotForm);
				mommy.signForm(robotForm);
				std::cout << robotForm << std::endl;
			TITLE("---Execute Signed Form---");
				daddy.executeForm(robotForm);
				mommy.executeForm(robotForm);
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	{
		try {
			INFO("\n*==================== President Testing ====================*\n");
			TITLE("---Create Executor---");
				Bureaucrat daddy("daddy", 150);
				Bureaucrat mommy("mommy", 3);
				std::cout << daddy << std::endl;
				std::cout << mommy << std::endl;
			TITLE("\n---Create PresidentialPardonForm---\n");
				PresidentialPardonForm presidentForm("presidentForm");
				std::cout << presidentForm << std::endl;
			TITLE("\n---Execute Unsigned Form---\n");
				daddy.executeForm(presidentForm);
				mommy.executeForm(presidentForm);
				std::cout << presidentForm << std::endl;
			TITLE("---Sign Form---");
				daddy.signForm(presidentForm);
				mommy.signForm(presidentForm);
				std::cout << presidentForm << std::endl;
			TITLE("---Execute Signed Form---");
				daddy.executeForm(presidentForm);
				mommy.executeForm(presidentForm);
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}

	}
	return 0;
}
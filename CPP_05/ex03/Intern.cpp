#include "sys.hpp"

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
	const std::string form[3] = {
		"shrubbery creation",
        "robotomy request",
        "presidential pardon"
	};

	AForm* (*creators[3])(const std::string&) = {
		[](const std::string& target)
		-> AForm* { return new ShrubberyCreationForm(target);},
		[](const std::string& target)
		-> AForm* { return new RobotomyRequestForm(target);},
		[](const std::string& target)
		-> AForm* { return new PresidentialPardonForm(target);}
	};

	for (int i = 0; i < 3; i++) {
		if (formName == form[i]) {
			SUCCESS("Intern creates " + formName);
			return creators[i](formTarget);
		}
	}
	ERROR_MSG("Intern cannot create form: " + formName);
	return nullptr;
}
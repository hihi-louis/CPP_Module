#include "sys.hpp"

int main()
{
	Intern intern;

	try{
		AForm* shrub = intern.makeForm("shrubbery creation", "shrubbery");
		if (shrub)
		{
			INFO(*shrub);
			delete shrub;
		}
	}catch (std::bad_alloc& e)
	{
		EXCEPTION(e.what());
	}

	try{
		AForm* robotomy = intern.makeForm("robotomy request", "robotomy");
		if (robotomy)
		{
			INFO(*robotomy);
			delete robotomy;
		}
	}catch (std::bad_alloc& e)
	{
		EXCEPTION(e.what());
	}

	try{
		AForm* presidential = intern.makeForm("presidential pardon", "presidential");
		if (presidential)
		{
			INFO(*presidential);
			delete presidential;
		}
	}catch (std::bad_alloc& e)
	{
		EXCEPTION(e.what());
	}

	TITLE("*=========Invalid test =========*");
	try	{
		AForm* noType = intern.makeForm("", "presiForm");
		if (noType)
		{
			INFO(*noType);
			delete noType;
		}
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try	{
		AForm* noTarget = intern.makeForm("presidential", "");
		if (noTarget)
		{
			INFO(*noTarget);
			delete noTarget;
		}
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}
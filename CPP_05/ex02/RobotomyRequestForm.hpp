#pragma once

#include <cstdlib> // for rand()
#include <ctime>   // for time()
#include "Bureaucrat.hpp"
#include "AForm.hpp"
class AForm;

class RobotomyRequestForm: public AForm{
	public:
		explicit RobotomyRequestForm(const std::string& target);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		void execute(Bureaucrat const & executor) const override;
		std::string    getTarget(void) const;

	private:
		std::string _target;
};
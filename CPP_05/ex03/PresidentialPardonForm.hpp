#pragma once

#include "sys.hpp"

class PresidentialPardonForm: public AForm{
	public:
		explicit PresidentialPardonForm(const std::string& target);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

		std::string getTarget(void) const;
		void execute(Bureaucrat const & executor) const override;
	private:
		std::string _target;
};
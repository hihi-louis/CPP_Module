#pragma once

#include "sys.hpp"

class ShrubberyCreationForm: public AForm{
	public:
		explicit ShrubberyCreationForm(const std::string& target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		void		execute(Bureaucrat const & executor) const override;
	private:
		std::string _target;	
};

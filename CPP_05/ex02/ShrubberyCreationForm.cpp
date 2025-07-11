/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:47:45 by tripham           #+#    #+#             */
/*   Updated: 2025/07/11 16:26:42 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137) ,_target(target){}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (!getIsSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::string filename = _target + "_shrubbery";
	std::ofstream outfile(filename);
	if (!outfile)
		throw std::runtime_error("Error: Could not open the file in  Shrubbery class");
	std::cout << "ShrubberyCreationForm: creating file " << filename << std::endl;
	outfile << "        ###\n"
			<< "       #o###\n"
			<< "     #####o###\n"
			<< "    #o#\\#|#/###\n"
			<< "     ###\\|/#o#\n"
			<< "      # }|{  #\n"
			<< "        }|{\n";
	outfile.close();
}
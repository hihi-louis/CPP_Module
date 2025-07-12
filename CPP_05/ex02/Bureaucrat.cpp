/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:51:23 by tripham           #+#    #+#             */
/*   Updated: 2025/07/11 18:14:17 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade){
	if (this->_grade < 1)
		throw GradeTooHighException();
	if (this->_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other){
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

void Bureaucrat::incrementGrade(){
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
}
void Bureaucrat::decrementGrade(){
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
}

const std::string&	Bureaucrat::getName(void) const{
	return this->_name;
}
int		Bureaucrat::getGrade(void) const{
	return this->_grade;
}

// void Bureaucrat::signForm(AForm& Aform)
// {
// 	//using try-catch, because AForm::beSigned(const Bureaucrat& b)
// 	// can throw an exception if Bureaucrat is too low level to sign Aforms
// 	try{
// 		Aform.beSigned(*this);
// 		//std::cout << this->_name << " signed " << Aform.getName() << std::endl;
// 		SUCCESS(this->_name + " signed " + Aform.getName());
// 	}
// 	catch (std::exception &e)
// 	{
// 		// std::cout << this->_name << " couldn't sign " << Aform.getName()
// 		// << " because " << e.what() << std::endl;
// 		EXCEPTION(this->_name + " couldn't sign " + Aform.getName() + " because " + e.what());
// 	}
// }

std::ostream& operator<<(std::ostream& out, const Bureaucrat& src)
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return out;
}
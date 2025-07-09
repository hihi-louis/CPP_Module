/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:51:23 by tripham           #+#    #+#             */
/*   Updated: 2025/07/09 16:34:07 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade){
	
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

std::ostream& operator<<(std::ostream& out, const Bureaucrat& src)
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return out;
}
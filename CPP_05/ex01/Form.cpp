/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:51:28 by tripham           #+#    #+#             */
/*   Updated: 2025/07/11 02:42:01 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form(std::string name, int gradeToSign, int gradeToExecute):
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
		if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
			throw GradeTooHighException();
		if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
			throw GradeTooLowException();
	}

Form::~Form() {}

Form::Form(const Form& other)
	: _name(other._name),
	  _isSigned(other._isSigned),
	  _gradeToSign(other._gradeToSign),
	  _gradeToExecute(other._gradeToExecute) {}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
		// _name, _gradeToSign, and _gradeToExecute are const and cannot be assigned
	}
	return *this;
}

std::string Form::getName() const { return this->_name;}

bool		Form::getIsSigned() const {return this->_isSigned;}

int			Form::getGradeToSign() const {return this->_gradeToSign;}

int			Form::getGradeToExecute() const {return this->_gradeToExecute;}

void		Form::beSigned(const Bureaucrat& o) {
	if (o.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	this->_isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& src){
	out << "Form: " << src.getName()
		<< ", signed: " << (src.getIsSigned() ? "yes" : "no")
		<< ", grade to sign: " << src.getGradeToSign()
		<< ", grade to execute : " << src.getGradeToExecute();
	return out;
}
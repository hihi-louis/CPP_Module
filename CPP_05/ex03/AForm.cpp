#include "sys.hpp"

AForm::AForm(std::string name, int gradeTosign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeTosign), _gradeToExecute(gradeToExecute){
		if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
			throw GradeTooHighException();
		if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
			throw GradeTooLowException();
	}

AForm::~AForm() {}


AForm::AForm(const AForm& other)
	: _name(other._name),
	  _isSigned(other._isSigned),
	  _gradeToSign(other._gradeToSign),
	  _gradeToExecute(other._gradeToExecute) {}

AForm& AForm::operator=(const AForm& other){
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

const std::string& AForm::getName() const { return this->_name;}

bool		AForm::getIsSigned() const {return this->_isSigned;}

int			AForm::getGradeToSign() const {return this->_gradeToSign;}

int			AForm::getGradeToExecute() const {return this->_gradeToExecute;}

void		AForm::beSigned(const Bureaucrat& o) {
	if (o.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	this->_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const noexcept{
	return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const noexcept{
	return "Grade too low!";
}

const char* AForm::NotSignedException::what() const noexcept{
	return "Form not signed!";
}

std::ostream& operator<<(std::ostream& out, const AForm& src){
	out << "Form: " << src.getName()
		<< ", signed: " << (src.getIsSigned() ? "yes" : "no")
		<< ", grade to sign: " << src.getGradeToSign()
		<< ", grade to execute : " << src.getGradeToExecute();
	return out;
}

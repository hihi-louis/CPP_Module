#include "sys.hpp"

// Bureaucrat::Bureaucrat(): _name("Undefined") , _grade(150) {}

Bureaucrat::~Bureaucrat() {}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return "Bureaucrat: Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return "Bureaucrat: Grade too low!";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade){
	if (this->_grade < 1)
		throw GradeTooHighException();
	if (this->_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other.getName()), _grade(other.getGrade()) {}

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

void Bureaucrat::signForm(AForm& form)
{
	/*
	 using try-catch, because Form::beSigned(const Bureaucrat& b)
	 can throw an exception if Bureaucrat is too low level to sign forms
	*/
	try{
		form.beSigned(*this);
		SUCCESS(this->_name + " signed " + form.getName());
	}
	catch (std::exception &e)
	{
		EXCEPTION(this->_name + " couldn't sign " + form.getName() + " because " + e.what());
	}
}

void Bureaucrat::executeForm(const AForm& form)
{
	try{
		form.execute(*this);
		SUCCESS(this->_name + " executed " + form.getName() + ".");
	}catch (const std::exception& e){
		EXCEPTION(this->_name + " couldn't execute " + form.getName()
			+ ", because " + e.what() + ".");
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& src)
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return out;
}
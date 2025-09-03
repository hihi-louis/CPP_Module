#include "sys.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
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
	
	// AForm::execute(executor); 
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
			<< "      # |||  #\n"
			<< "        |||\n";
	outfile.close();
}
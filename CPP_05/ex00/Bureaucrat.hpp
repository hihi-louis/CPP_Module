#pragma once

#include <iostream>
#include <new>
#include <exception>

class Bureaucrat{
	public:
		Bureaucrat() = delete;
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other) = delete;
		
		const std::string&	getName(void) const;
		int		getGrade(void) const;
		
		//Grade manipulation
		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception{
			public:
				const char* what() const noexcept override;
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
		private:
		const std::string _name;
		int				  _grade;
	};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& src);
	
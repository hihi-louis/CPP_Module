/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:55:51 by tripham           #+#    #+#             */
/*   Updated: 2025/07/12 13:36:37 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <new>
#include "AForm.hpp"

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

# define INFO(msg)		std::cout << CYAN << msg << RESET << std::endl
# define SUCCESS(msg)	std::cout << GREEN << msg << RESET << std::endl
# define ERROR_MSG(msg)	std::cout << RED << msg << RESET << std::endl
# define EXCEPTION(msg)	std::cout << YELLOW << msg << RESET << std::endl

class Form;
class Bureaucrat{
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		
		const std::string&	getName(void) const;
		int		getGrade(void) const;
		
		//Grade manipulation
		void incrementGrade();
		void decrementGrade();
		void signForm(Form& form);
		class GradeTooHighException : public std::exception{
			public:
				const char* what() const throw() {
					return "Bureaucrat: Grade too high!";
				}
		};
		
		class GradeTooLowException : public std::exception {
			public:
			const char* what() const throw() {
				return "Bureaucrat: Grade too low!";
			}
		};
		private:
		const std::string _name;
		int				  _grade;
	};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& src);
	
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:39:26 by tripham           #+#    #+#             */
/*   Updated: 2025/07/11 02:43:12 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp" 
#include <iostream>

class Bureaucrat; // Forward Declaration to let compiler to know this class is going to defined later.

class Form{
	public:
		Form(const std::string name, int gradeToSign, int gradeToExecute);
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
		
		std::string getName() const;
		bool		getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		void		beSigned(const Bureaucrat& o);
		
		class GradeTooHighException : public std::exception{
			public:
				const char* what() const throw() {
					return "Form: Grade too high!";
				}
		};
		
		class GradeTooLowException : public std::exception {
			public:
			const char* what() const throw() {
				return "Form: Grade too low!";
			}
		};		
	private:
		const std::string 	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream& operator<<(std::ostream& out, const Form& src);

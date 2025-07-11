/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 03:20:31 by tripham           #+#    #+#             */
/*   Updated: 2025/07/11 14:52:24 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
	public:
		AForm(std::string name, int gradeTosign, int gradeToExecute);
		virtual ~AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		
		const std::string& 	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(const Bureaucrat& o);
		virtual void		execute(Bureaucrat const & executor) const = 0; //pure virtual
		
		class GradeTooHighException : public std::exception{
			const char* what() const throw() override;
		};
		
		class GradeTooLowException : public std::exception {
			const char* what() const throw() override; 
		};	

		class NotSignedException : public std::exception {
			const char* what() const throw() override;
		};
		
		class NotSignedException : public std::exception {
		public:
			const char* what() const throw() override;
		};
		
	protected:
		const std::string 	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream& operator<<(std::ostream& out, const AForm& src);
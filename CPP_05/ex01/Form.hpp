/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:39:26 by tripham           #+#    #+#             */
/*   Updated: 2025/07/10 14:57:41 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"

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
		void		beSigned(const Bureaucrat& other);
		
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
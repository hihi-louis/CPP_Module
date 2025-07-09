/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:55:51 by tripham           #+#    #+#             */
/*   Updated: 2025/07/09 15:50:34 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <new>

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
	
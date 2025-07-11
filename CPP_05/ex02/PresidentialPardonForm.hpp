/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:17:51 by tripham           #+#    #+#             */
/*   Updated: 2025/07/11 15:23:23 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm: public AForm{
	public:
		PresidentialPardonForm(const std::string& name, int gradeToSign, int gradeToExecute);
		~PresidentialPardonForm();
		PresidentialPardonForm(const Form& other);
		PresidentialPardonForm& operator=(const Form& other);

		const std::string& 	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(const Bureaucrat& o);
		void		execute(Bureaucrat const & executor) const override;
		void		ASCIItoTree();
	private:
		const std::string 	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;		
};

std::ostream& operator<<(std::ostream& out, PresidentialPardonForm & src);
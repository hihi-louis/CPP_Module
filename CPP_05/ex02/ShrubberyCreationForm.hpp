/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:24:24 by tripham           #+#    #+#             */
/*   Updated: 2025/07/11 16:25:44 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>  // for std::ofstream
#include <stdexcept> // for std::runtime_error

class ShrubberyCreationForm: public AForm{
	public:
		explicit ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		void		execute(Bureaucrat const & executor) const override;
	private:
		std::string _target;	
};

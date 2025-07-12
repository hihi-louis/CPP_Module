/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:58:37 by tripham           #+#    #+#             */
/*   Updated: 2025/07/12 15:43:12 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib> // for rand()
#include <ctime>   // for time()
#include "Bureaucrat.hpp"
#include "AForm.hpp"
class AForm;

class RobotomyRequestForm: public AForm{
	public:
		explicit RobotomyRequestForm(const std::string& target);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		void execute(Bureaucrat const & executor) const override;
		std::string    getTarget(void) const;

	private:
		std::string _target;
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:32:19 by tripham           #+#    #+#             */
/*   Updated: 2025/07/12 17:58:42 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45) , _target(target){}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

std::string    RobotomyRequestForm::getTarget(void) const{
		return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	AForm::execute(executor);
	std::cout << "Makes some drilling noises" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->_target + " has been robotomized successfully 50% of the time." << std::endl;
	else
		std::cout <<"the robotomy failed." << std::endl;

}
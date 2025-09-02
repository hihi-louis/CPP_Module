/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 23:57:17 by tripham           #+#    #+#             */
/*   Updated: 2025/09/01 16:46:55 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {
	std::cout << "Cure: Default constructor called" << std::endl;
}

Cure::~Cure(){
	std::cout << "Cure: Default destructor called" << std::endl;
}

Cure::Cure(const Cure& other): AMateria(other) { //AMateria(other) is already copied other
	std::cout << "Cure: Copy constructor called" << std::endl;
	//do not need to copy again in here: *this = other
}

Cure& Cure::operator=(const Cure& other) {
	std::cout << "Cure: Copy assignment called" << std::endl;
	(void)other;
	return *this;
}

AMateria* Cure::clone() const{
	return new Cure(*this);
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

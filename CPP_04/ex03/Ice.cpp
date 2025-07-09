/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:14:40 by tripham           #+#    #+#             */
/*   Updated: 2025/07/09 00:44:04 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {
	std::cout << "Ice: Default constructor called" << std::endl;
}

Ice::~Ice(){
	std::cout << "Ice: Default destructor called" << std::endl;
}

Ice::Ice(const Ice& other): AMateria(other) { //AMateria(other) is already copied other
	std::cout << "Ice: Copy constructor called" << std::endl;
	//do not need to copy again in here: *this = other
}

Ice& Ice::operator=(const Ice& other) {
	std::cout << "Ice: Copy assignment called" << std::endl;
	(void)other;
	return *this;
}

AMateria* Ice::clone() const{
	return new Ice(*this);
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

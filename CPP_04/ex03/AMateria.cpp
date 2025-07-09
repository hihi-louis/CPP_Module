/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:27:36 by tripham           #+#    #+#             */
/*   Updated: 2025/07/08 23:56:42 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const& type): _type(type){
	std::cout << "AMateria: Default constructor called with: " << this->_type << std::endl; 
}

AMateria::~AMateria(){
	std::cout << "AMateria: Default destructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other): _type(other._type){

}

AMateria& AMateria::operator=(const AMateria& other){
	(void)other;
	return *this;
}

std::string const & AMateria::getType() const{
	return _type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "AMateria is using materia on " << target.getName() << std::endl;
}
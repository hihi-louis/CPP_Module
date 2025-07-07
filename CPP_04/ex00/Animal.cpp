/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:22:30 by tripham           #+#    #+#             */
/*   Updated: 2025/07/07 16:34:14 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("Undefined Animal"){
	LOG("Animal: Default constructor called");
}

Animal::~Animal() {
	LOG("Animal: Default destructor called");
}

Animal::Animal(std::string type): _type(type){
	LOG("Animal: Parameterized constructor called");
}

Animal::Animal(const Animal& other)
{
	LOG("Animal: Copy constructor called");
	*this = other;
}

Animal& Animal::operator=(const Animal& other)
{
	LOG("Animal: Copy assignment called");
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

void Animal::makeSound() const{
	std::cout << "Animal's sound" << std::endl;
}

std::string Animal::getType() const {
	return _type;
}
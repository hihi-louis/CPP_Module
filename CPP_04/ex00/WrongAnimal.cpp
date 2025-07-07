/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 01:40:29 by tripham           #+#    #+#             */
/*   Updated: 2025/07/08 01:50:33 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("Undefined wrong animal"){
	LOG("WrongAnimal: Default constructor called");
}

WrongAnimal::~WrongAnimal() {
	LOG("WrongAnimal: Default destructor called");
}

WrongAnimal::WrongAnimal(std::string type): _type(type){
	LOG("WrongAnimal: Parameterized constructor called");
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	LOG("WrongAnimal: Copy constructor called");
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	LOG("WrongAnimal: Copy assignment called");
	if (this != &other)
		this->_type = other._type;
	return *this;
}

std::string WrongAnimal::getType() const
{
	return this->_type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Olala" << std::endl;
}
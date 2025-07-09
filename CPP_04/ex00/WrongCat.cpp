/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 01:51:21 by tripham           #+#    #+#             */
/*   Updated: 2025/07/09 04:38:21 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("Demon"){
	LOG("WrongCat: Default constructor called");
}

WrongCat::~WrongCat() {
	LOG("WrongCat: Default destructor called");
}

WrongCat::WrongCat(std::string type): WrongAnimal(type){
	LOG("WrongCat: Parameterized constructor called");
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
	LOG("WrongCat: Copy constructor called");
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	LOG("WrongCat: Copy assignment called");
	if (this != &other)
		this->_type = other._type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Mon Leo" << std::endl;
}
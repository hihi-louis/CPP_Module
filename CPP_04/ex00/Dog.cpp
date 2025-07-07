/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:12:34 by tripham           #+#    #+#             */
/*   Updated: 2025/07/07 17:13:41 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Undefined type"){
	LOG("Dog: Default constructor called");
}

Dog::~Dog() {
	LOG("Dog: Default destructor called");
}

Dog::Dog(std::string type): Animal(type){
	LOG("Dog: Parameterized constructor called");
}

Dog::Dog(const Dog& other): Animal(other)
{
	LOG("Dog: Copy constructor called");
}
Dog& Dog::operator=(const Dog& other)
{
	LOG("Dog: Copy assignment called");
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return *this;
}

void Dog::makeSound() const 
{
	std::cout << "Woof Woof" << std::endl;
}
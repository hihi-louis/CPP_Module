/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:37:01 by tripham           #+#    #+#             */
/*   Updated: 2025/07/08 02:49:36 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat"){
	LOG("Cat: Default constructor called");
}

Cat::~Cat() {
	LOG("Cat: Default destructor called");
}

Cat::Cat(std::string type): Animal(type){
	LOG("Cat: Parameterized constructor called");
}

Cat::Cat(const Cat& other): Animal(other)
{
	LOG("Cat: Copy constructor called");
}
Cat& Cat::operator=(const Cat& other)
{
	LOG("Cat: Copy assignment called");
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return *this;
}

void Cat::makeSound() const 
{
	std::cout << "Meow Meow" << std::endl;
}
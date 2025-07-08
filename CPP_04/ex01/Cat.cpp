/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:37:01 by tripham           #+#    #+#             */
/*   Updated: 2025/07/08 04:52:42 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	LOG("Cat: Default constructor called");
	this->_type = "Cat";
	
	try{
		this->_brain = new Brain();
	} catch(const std::bad_alloc& err) {
		std::cerr << "Failed to allocate Brain: " << err.what() << std::endl;
		throw;
	}
}

Cat::~Cat() {
	LOG("Cat: Default destructor called");
	delete this->_brain;
}

Cat::Cat(std::string type): Animal(type){
	LOG("Cat: Parameterized constructor called");
	try{
		this->_brain = new Brain();
	} catch(const std::bad_alloc& err) {
		std::cerr << "Failed to allocate Brain: " << err.what() << std::endl;
		throw;
	}
}

Cat::Cat(const Cat& other): Animal(other)
{
	this->_brain = new Brain(*other._brain); // deep copy
	LOG("Cat: Copy constructor called");
}
Cat& Cat::operator=(const Cat& other)
{
	LOG("Cat: Copy assignment called");
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->_brain; // remove the old brain
		this->_brain = new Brain(*other._brain); // Deep copy the new brain
	}
	return *this;
}

void Cat::makeSound() const 
{
	std::cout << "Meow Meow" << std::endl;
}
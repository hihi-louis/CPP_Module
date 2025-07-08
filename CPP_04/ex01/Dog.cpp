/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:12:34 by tripham           #+#    #+#             */
/*   Updated: 2025/07/08 17:04:30 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog"){
	LOG("Dog: Default constructor called");
	try{
		this->_brain = new Brain();
	} catch(const std::bad_alloc& err) {
		std::cerr << "Failed to allocate Brain: " << err.what() << std::endl;
		throw;
	}
}

Dog::~Dog() {
	LOG("Dog: Default destructor called");
	delete this->_brain;
}

Dog::Dog(std::string type): Animal(type){
	LOG("Dog: Parameterized constructor called");
	try{
		this->_brain = new Brain();
	} catch(const std::bad_alloc& err) {
		std::cerr << "Failed to allocate Brain: " << err.what() << std::endl;
		throw;
	}
}

Dog::Dog(const Dog& other): Animal(other)
{
	this->_brain = new Brain(*other._brain); // deep copy
	LOG("Dog: Copy constructor called");
}
Dog& Dog::operator=(const Dog& other)
{
	LOG("Dog: Copy assignment called");
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->_brain; // remove the old brain
		this->_brain = new Brain(*other._brain); // Deep copy the new brain
	}
	return *this;
}

void Dog::makeSound() const 
{
	std::cout << "Woof Woof" << std::endl;
}

Brain* Dog::getBrain() const{
	return _brain;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:12:34 by tripham           #+#    #+#             */
/*   Updated: 2025/09/01 15:49:47 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog"){
	LOG("Dog: Default constructor called");
	try{
		this->_brain = new Brain();
	} catch(const std::bad_alloc& err) {
		std::cout << "Failed to allocate Brain: " << err.what() << std::endl;
		throw;
	}
}

Dog::~Dog() {
	LOG("Dog: Default destructor called");
	delete this->_brain;
}

Dog::Dog(std::string type): Animal(type), _brain(nullptr) {
	LOG("Dog: Parameterized constructor called");
	try{
		this->_brain = new Brain();
	} catch(const std::bad_alloc& err) {
		std::cout << "Failed to allocate Brain: " << err.what() << std::endl;
		throw;
	}
}

Dog::Dog(const Dog& other): Animal(other)
{
	LOG("Dog: Copy constructor called");
	*this = other;
}

Dog& Dog::operator=(const Dog& other)
{
	LOG("Dog: Copy assignment called");
	if (this != &other)
	{
		Animal::operator=(other);
		Brain* newBrain = nullptr;
		try {
			newBrain = new Brain(*other._brain);
        } catch (const std::bad_alloc& e) {
			std::cerr << "Failed to copy Brain: " << e.what() << std::endl;
            throw;
        }
		if (this->_brain)
			delete this->_brain;
        this->_brain = newBrain;
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
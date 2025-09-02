/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:37:01 by tripham           #+#    #+#             */
/*   Updated: 2025/09/01 15:49:22 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    LOG("Cat: Default constructor called");
    try {
        this->_brain = new Brain();
    } catch (const std::bad_alloc& err) {
        std::cerr << "Failed to allocate Brain: " << err.what() << std::endl;
        throw;
    }
}

Cat::~Cat() {
    LOG("Cat: Destructor called");
    delete this->_brain;
}

Cat::Cat(std::string type) : Animal(type), _brain(nullptr) {
    LOG("Cat: Parameterized constructor called");
    try {
        this->_brain = new Brain();
    } catch (const std::bad_alloc& err) {
        std::cerr << "Failed to allocate Brain: " << err.what() << std::endl;
        throw;
    }
}

Cat::Cat(const Cat& other) : Animal(other) {
    LOG("Cat: Copy constructor called");
    *this = other;
}

Cat& Cat::operator=(const Cat& other) {
    LOG("Cat: Copy assignment called");
    if (this != &other) {
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

void Cat::makeSound() const {
    std::cout << "Meow Meow" << std::endl;
}

Brain* Cat::getBrain() const {
    return this->_brain;
}
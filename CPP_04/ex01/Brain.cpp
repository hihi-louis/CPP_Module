/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 03:29:27 by tripham           #+#    #+#             */
/*   Updated: 2025/09/01 15:43:52 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	LOG("Brain: Default constructor called");
	for (int i = 0; i < 100; i++)
    	this->_ideas[i] = "";
}
Brain::~Brain() {
	LOG("Brain: Default destructor called");
}

Brain::Brain(const Brain& other) {
	LOG("Brain: Copy constructor called");
	*this = other;
}
	
Brain& Brain::operator=(const Brain &other) {
	LOG("Brain: Copy assignment called");
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return *this;
}

void Brain::setIdea(int index, const std::string& idea){
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
	else
        std::cout << "Invalid idea index: " << index << std::endl;
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100)
		return this->_ideas[index];
	std::cout << "Invalid idea index: " << index << std::endl;
    return "";
}


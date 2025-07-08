/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 03:29:27 by tripham           #+#    #+#             */
/*   Updated: 2025/07/08 03:34:32 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	LOG("Brain: Default constructor called");
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



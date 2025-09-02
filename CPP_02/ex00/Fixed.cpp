/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:19:00 by tripham           #+#    #+#             */
/*   Updated: 2025/08/03 18:42:15 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _number(0) {
	LOG("Default constructor called");
}

Fixed::~Fixed() {
	LOG("Destructor called");
}

Fixed::Fixed(const Fixed& other){
	LOG("Copy constructor called");
	this->_number = other._number;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	LOG("Copy assignment operator called");
	if (this != &other)
		this->_number = other._number;
	return *this;
}

int Fixed::getRawBits( void ) const {
	LOG("getRawBits member function called");
	return _number;
}

void Fixed::setRawBits( int const raw ){
	_number = raw;
}
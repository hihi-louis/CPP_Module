/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:40:08 by tripham           #+#    #+#             */
/*   Updated: 2025/07/04 18:06:15 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {LOG("Default constructor called");}

Fixed::Fixed(const int number): _value(number << _fractionalBits){
	LOG("Int constructor called");
} 

Fixed::Fixed(const float number): _value(roundf(number * (1 << this->_fractionalBits))){
	LOG("Float constructor called");
}

Fixed::~Fixed() {LOG("Destructor called");}

float Fixed::toFloat( void ) const{
	return ((float) this->_value / (1 << this->_fractionalBits));
}

int 	Fixed::toInt( void ) const{
	return (this->_value >> this->_fractionalBits);
}

Fixed::Fixed(const Fixed& other){
	LOG("Copy constructor called");
	*this = other; //Using construtor operator=
}

Fixed& Fixed::operator=(const Fixed& other) {
	LOG("Copy assignment operator called");
	if (this != &other)
		this->_value = other._value;//getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const {
	return this->_value;
}

void Fixed::setRawBits( int const raw ){
	this->_value = raw;
}

std::ostream& operator<<(std::ostream &os, Fixed const& obj)
{
	os << obj.toFloat();
	return (os);	
}
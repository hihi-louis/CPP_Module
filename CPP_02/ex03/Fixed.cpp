/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:40:08 by tripham           #+#    #+#             */
/*   Updated: 2025/07/12 13:36:37 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _value(0) {}

Fixed::Fixed(const int number): _value(number << _fractionalBits){} 

Fixed::Fixed(const float number): _value(roundf(number * (1 << this->_fractionalBits))){}

Fixed::~Fixed() {}

float Fixed::toFloat( void ) const{
	return ((float) this->_value / (1 << this->_fractionalBits));
}

int 	Fixed::toInt( void ) const{
	return (this->_value >> this->_fractionalBits);
}

Fixed::Fixed(const Fixed& other){
	*this = other; //Using construtor operator=
}

Fixed& Fixed::operator=(const Fixed& other) {
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

bool	Fixed::operator>(const Fixed& other) const {return (this->getRawBits() > other.getRawBits());}
bool	Fixed::operator<(const Fixed& other) const {return (this->getRawBits() < other.getRawBits());}
bool	Fixed::operator>=(const Fixed& other) const {return (this->getRawBits() >= other.getRawBits());}
bool	Fixed::operator<=(const Fixed& other) const {return (this->getRawBits() <= other.getRawBits());}
bool	Fixed::operator==(const Fixed& other) const {return (this->getRawBits() == other.getRawBits());}
bool	Fixed::operator!=(const Fixed& other) const {return (this->getRawBits() != other.getRawBits());}

Fixed Fixed::operator+(const Fixed& other) const{return (Fixed)(this->toFloat() + other.toFloat());}	
Fixed Fixed::operator-(const Fixed& other) const{return (Fixed)(this->toFloat() - other.toFloat());}
Fixed Fixed::operator*(const Fixed& other) const{return (Fixed)(this->toFloat() * other.toFloat());}
Fixed Fixed::operator/(const Fixed& other) const {
	if (other._value == 0) {
		std::cout << "Division by zero\n";
		return Fixed();
	}
	return (Fixed)(this->toFloat() / other.toFloat());
}


Fixed& Fixed::operator++(void) {
	this->_value++;
	return *this;
}

Fixed  Fixed::operator++(int) {
	Fixed temp(*this);
	this->_value++;
	return temp;
}

Fixed& Fixed::operator--(void) {
	this->_value--;
	return *this;
}

Fixed  Fixed::operator--(int) {
	Fixed temp(*this);
	this->_value--;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {return (a < b ? a : b);}
Fixed& Fixed::max(Fixed& a, Fixed& b) {return (a > b ? a : b);}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {return (a < b ? a : b);}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)  {return (a > b ? a : b);}

std::ostream& operator<<(std::ostream &os, Fixed const& obj)
{
	os << obj.toFloat();
	return (os);	
}
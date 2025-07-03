/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:33:29 by tripham           #+#    #+#             */
/*   Updated: 2025/07/04 02:32:56 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed {
	public:
		Fixed();								// Default constructor
		Fixed(const int number);				// Int constructor
		Fixed(const float number);				// Float constructor
		Fixed(const Fixed& other);				// Copy constructor
		Fixed& operator=(const Fixed& other);	// Copy assignment operator
		~Fixed();							// Destructor

		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
		//Comparison operators
		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;
		
		//Arithmetic operators
		Fixed operator+(const Fixed& other) const;	
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;
	
		//increment/decrement
		Fixed& operator++(void);
		Fixed  operator++(int);
		Fixed& operator--(void);
		Fixed  operator--(int);

		//min/max

		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

	private:
		int					_value;
		static const int	_fractionalBits = 8;
};

std::ostream& operator<<(std::ostream &os, Fixed const& obj);
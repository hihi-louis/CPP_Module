/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:33:29 by tripham           #+#    #+#             */
/*   Updated: 2025/07/04 00:44:12 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

#define LOG(message) std::cout << "\033[38;5;218m" << message << "\033[0m" << std::endl

class Fixed {
	public:
		Fixed();								// Default constructor
		Fixed(const int number);				// Int constructor
		Fixed(const float number);				// Float constructor
		Fixed(const Fixed& other);				// Copy constructor
		Fixed& operator=(const Fixed& other);	// Copy assignment operator
		~Fixed();								// Destructor

		float	toFloat(void) const;
		int		toInt(void) const;

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					_value;
		static const int	_fractionalBits = 8;
};

std::ostream& operator<<(std::ostream &os, Fixed const& obj);
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:19:03 by tripham           #+#    #+#             */
/*   Updated: 2025/07/03 18:27:00 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#define LOG(msg) std::cout << "\033[38;5;218m" << msg << "\033[0m" << std::endl

class Fixed {
	public:
		Fixed(); //Constructor
		~Fixed(); // Destructor
		Fixed(const Fixed& number); // A copy constructor
		Fixed& operator=(const Fixed& other);

		int getRawBits( void ) const; // getter always goes with cosnt, cuz it just gets the value, does'n change the value
		void setRawBits( int const raw );
	private:
		int					_number;
		static const int	_fractionalBits = 8;
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:41:13 by tripham           #+#    #+#             */
/*   Updated: 2025/06/27 18:13:59 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::complain( std::string level )
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*handlers[4]) (void) = 
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};

	bool matched = false;
	for (int i = 0; i < 4; i++)
	{
		//using bitwise to return matched value to use for fallback 
		// if level == levels[i] -> true, ((this->*handlers[i])(), true) return true value
		// false = 0, true = 1, in bitwise (|=) 0 + 1 = 1 => true
		// bitwise OR assignment (|=)
		/*
			int a = 5;   // 0101 (bit)
			int b = 3;   // 0011 (bit)

			a |= b;      // a = a | b → 0101 | 0011 = 0111 → 7
		*/
		matched |= (level == levels[i]) && ((this->*handlers[i])(), true);
	}

	const char* fallback[2] = {
		"Probably complaining about insignificant problems.\n",
		""
	};

	std::cout << fallback[matched];
}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]\n" << DEBUG << std::endl;
}

void Harl::info( void )
{
	std::cout <<"[ INFO ]\n"<< INFO << std::endl;
}

void Harl::warning( void ) 
{
	std::cout << "[ WARNING ]\n"<< WARNING << std::endl;
}

void Harl::error( void )
{
	std::cout <<"[ ERROR ]\n"<< ERROR << std::endl;
}
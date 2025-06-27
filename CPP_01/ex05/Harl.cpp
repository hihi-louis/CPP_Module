/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:41:13 by tripham           #+#    #+#             */
/*   Updated: 2025/06/27 17:19:25 by tripham          ###   ########.fr       */
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
		matched |= (level == levels[i]) && ((this->*handlers[i])(), true);
	}

	const char* fallback[2] = {
		"Probably complaining about insignificant problems.",
		""
	};

	std::cout << fallback[matched] << std::endl;
}

void Harl::debug( void )
{
	std::cout << DEBUG << std::endl;
}

void Harl::info( void )
{
	std::cout << INFO << std::endl;
}

void Harl::warning( void ) 
{
	std::cout << WARNING << std::endl;
}

void Harl::error( void )
{
	std::cout << ERROR << std::endl;
}
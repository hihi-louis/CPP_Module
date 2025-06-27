/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:29:33 by tripham           #+#    #+#             */
/*   Updated: 2025/06/27 16:11:30 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

# define DEBUG "I love having extra bacon for my burger. I really do!"
# define INFO "I cannot believe adding extra bacon costs more money."
# define WARNING "I think I deserve to have some extra bacon for free."
# define ERROR "This is unacceptable! I want to speak to the manager now."
# define INVALID "Invalid complaint level!"

class Harl{
	public:
	
		Harl();
		~Harl();

		void complain( std::string level );
		
	private:
	
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};
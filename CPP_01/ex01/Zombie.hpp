/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:56:11 by tripham           #+#    #+#             */
/*   Updated: 2025/06/27 18:15:56 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

 #include <iostream>
 #include <string>
 #include <new>
 
	class Zombie {
		public:
			/*Contructior*/
			Zombie();
			/*Destructor*/
			~Zombie();
	
			void announce( void );
			void setName(std::string name);
		private:
			std::string _name;
	};
	Zombie* zombieHorde( int N, std::string name );

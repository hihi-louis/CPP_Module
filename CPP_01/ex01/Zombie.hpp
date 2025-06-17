/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:56:11 by tripham           #+#    #+#             */
/*   Updated: 2025/06/17 18:57:52 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIELOUIS_HPP
 #define ZOMBIELOUIS_HPP

 #include <iostream>
 #include <string>
 #include <new>
 
namespace ZombieLouis {
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
}
#endif
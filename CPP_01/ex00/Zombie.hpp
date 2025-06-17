/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:56:11 by tripham           #+#    #+#             */
/*   Updated: 2025/06/17 17:44:03 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE
 #define ZOMBIE

 #include <iostream>
 #include <string>
 #include <new>
 
class Zombie {
	public:
		/*Contructior*/
		Zombie(std::string name);
		/*Destructor*/
		~Zombie();

		void announce( void );
	private:
		std::string _name;
};
Zombie* newZombie(std::string name);
void randomChump(std::string name);
#endif
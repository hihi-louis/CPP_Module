/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:42:55 by tripham           #+#    #+#             */
/*   Updated: 2025/06/17 19:06:36 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

namespace ZombieLouis {
	Zombie::Zombie() {}
	
	Zombie::~Zombie() {
		std::cout << _name << ": die" << std::endl;
	}
	
	void Zombie::announce (void) {
		std::cout << _name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
	}
	void Zombie::setName(std::string name) {
		_name = name;
	}
}
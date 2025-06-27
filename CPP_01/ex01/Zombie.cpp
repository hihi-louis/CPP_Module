/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:42:55 by tripham           #+#    #+#             */
/*   Updated: 2025/06/27 18:15:33 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
	
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
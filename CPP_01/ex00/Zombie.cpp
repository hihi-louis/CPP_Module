/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:16:04 by tripham           #+#    #+#             */
/*   Updated: 2025/06/17 17:58:27 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name): _name(name) {} /*Using initialization list to assign name*/

Zombie::~Zombie() {
	std::cout << _name << ": die" << std::endl;
}

void Zombie::announce (void) {
	std::cout << _name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:22:54 by tripham           #+#    #+#             */
/*   Updated: 2025/07/12 13:42:42 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


	HumanB::HumanB(const std::string &name): _name(name.empty() ? "undifined" : name) {
		this->_weapon = nullptr;
	}
	HumanB::~HumanB() {}

	void HumanB::attack()
	{
		if (_weapon)
			std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
		else
			std::cout << _name << " attacks without weapon" << std::endl;
	}
	
	void HumanB::setWeapon(const Weapon &_weapon)
	{
		this->_weapon = &_weapon;
	}
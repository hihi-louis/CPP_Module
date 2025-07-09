/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 04:16:23 by tripham           #+#    #+#             */
/*   Updated: 2025/07/09 04:42:33 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap() {
	_hitPoint = 100;
    _energyPoint = 50;
    _attackDamage = 30;
	LOG("DiamondTrap: Default constructor called");
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), _name(name)
{
	_hitPoint = 100;
    _energyPoint = 50;
    _attackDamage = 30;
	LOG("DiamondTrap: Parameterized constructor called");
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other._name + "_clap_name"), ScavTrap(other), FragTrap(other), _name(other._name)
{
	LOG("DiamondTrap: Copy constructor called");
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap& other)
{
	LOG("DiamondTrap: Copy assignment called");
	if (this != &other)
	{
		ClapTrap::operator=(other); 
		this->_name = other._name;
        this->_attackDamage = other._attackDamage;
        this->_hitPoint = other._hitPoint;
        this->_energyPoint = other._energyPoint;
	}
	return *this;
}

DiamondTrap::~DiamondTrap(){
	LOG("DiamondTrap: Default destructor called");
}

void DiamondTrap::whoAmI(){
	std::cout << "name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << this->ClapTrap::_name << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 00:00:10 by tripham           #+#    #+#             */
/*   Updated: 2025/07/07 01:27:55 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("Defaul ScavTrap called"){
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
	LOG("ScavTrap: Default constructor called");
}

ScavTrap::~ScavTrap(){
	LOG("ScavTrap: Default destructor called");
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name.empty() ? "Undefined" : name){
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
	LOG("ScavTrap: Parameterized constructor called");
}

ScavTrap::ScavTrap(const ScavTrap& other){
	LOG("ScavTrap: Copy constructor called");
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
	LOG("ScavTrap: Copy assignment called");
	if (this != &other)
	{
		this->_name = other._name;
        this->_attackDamage = other._attackDamage;
        this->_hitPoint = other._hitPoint;
        this->_energyPoint = other._energyPoint;
	}
	return *this;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target){
	if (this->_hitPoint <= 0 || this->_energyPoint <= 0)
    {
        std::cout << "ScavTrap " << this->_name << " has no energy or is already dead and cannot attack." << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    this->_energyPoint--;
}
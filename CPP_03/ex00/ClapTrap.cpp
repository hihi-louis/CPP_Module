/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:56:05 by tripham           #+#    #+#             */
/*   Updated: 2025/07/04 18:30:11 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Undefined ClapTrap"),
                      _hitPoint(10),
                      _energyPoint(10),
                      _attackDamage(0)
{
	LOG("ClapTrap: Default constructor called");
}
ClapTrap::~ClapTrap() 
{
	LOG("ClapTrap: Default destructor called");
}

ClapTrap::ClapTrap(std::string name): _name(name.empty() ? "Undefined ClapTrap" : name),
                                      _hitPoint(10),
                                      _energyPoint(10),
                                      _attackDamage(0) 
{
	LOG("ClapTrap: Default constructor called");
}

ClapTrap::ClapTrap(const ClapTrap& other){
	LOG("ClapTrap: Copy constructor called");
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
	LOG("ClapTrap: Copy assignment called");
    if (this != &other)
    {   
        this->_name = other._name;
        this->_attackDamage = other._attackDamage;
        this->_hitPoint = other._hitPoint;
        this->_energyPoint = other._energyPoint;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (this->_hitPoint <= 0 || this->_energyPoint <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " has no energy or is already dead and cannot attack." << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    this->_energyPoint--;
};

void ClapTrap::takeDamage(unsigned int amount){
	
    if (this->_hitPoint == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already destroyed!" << std::endl;
        return;
	}
	if (amount >= this->_hitPoint)
		this->_hitPoint = 0;
	else
		this->_hitPoint -= amount;
	
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage! "
         << "Remaining HP: " << this->_hitPoint << std::endl;
};

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_hitPoint <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already destroyed!" << std::endl;
        return;
	}
	else if (this->_energyPoint <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy left to repair." << std::endl;
        return;
	}
	else
	{
		std::cout << this->_name << "got repaired" << std::endl;
		if (amount + this->_hitPoint >= 10)
			this->_hitPoint = 10;
		this->_energyPoint--;
	}
	
}

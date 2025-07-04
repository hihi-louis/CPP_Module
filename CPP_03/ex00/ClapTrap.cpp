/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:56:05 by tripham           #+#    #+#             */
/*   Updated: 2025/07/04 14:14:20 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Undefined ClapTrap"),
                      _hitPoint(10),
                      _energyPoint(10),
                      _attackDamage(0){}
ClapTrap::~ClapTrap(){}

ClapTrap::ClapTrap(std::string name): _name(name.empty() ? "Undefined ClapTrap" : name),
                                      _hitPoint(10),
                                      _energyPoint(10),
                                      _attackDamage(0) {}

ClapTrap::ClapTrap(const ClapTrap& other){
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
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
    if (_hitPoint <= 0 || _energyPoint <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy or is already dead and cannot attack." << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoint--;
};

void ClapTrap::takeDamage(unsigned int amount){
    if (_)
};
void ClapTrap::beRepaired(unsigned int amount){};
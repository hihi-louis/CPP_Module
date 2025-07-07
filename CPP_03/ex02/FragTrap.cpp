/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 02:37:58 by tripham           #+#    #+#             */
/*   Updated: 2025/07/07 03:29:30 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap(){
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
	LOG("FragTrap: Default constructor called");
}

FragTrap::~FragTrap(){
	LOG("FragTrap: Default destructor called");
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name.empty() ? "Undefine" : name){
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
	LOG("FragTrap: Parameterized constructor called");
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other){
	LOG("FragTrap: Copy constructor called");
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other){
	LOG("FragTrap: Copy assignment called");
	if (this != &other)
	{
		this->_name = other._name;
        this->_attackDamage = other._attackDamage;
        this->_hitPoint = other._hitPoint;
        this->_energyPoint = other._energyPoint;
	}
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "This is positive highFives" << std::endl;
}
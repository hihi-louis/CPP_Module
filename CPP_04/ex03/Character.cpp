/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 02:52:16 by tripham           #+#    #+#             */
/*   Updated: 2025/07/09 03:51:58 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {
	std::cout << "Character: Default constructor called" << std::endl;
}

Character::~Character() {
	std::cout << "Character: Default destructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
		if (_inventory[i])
			delete _inventory[i];

	for (int i = 0; i < _floorIndex; ++i)
		if (_floor[i])
			delete _floor[i];
}

Character::Character(std::string name): _name(name), _floorIndex(0)
{
	std::cout << "Character: Paramrterzied constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
	for (int i = 0; i < 100; i++)
		this->_floor[i] = nullptr;
}

Character::Character(const Character& other): _name(other._name), _floorIndex(0) {
	std::cout << "Character: Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : nullptr;
	for (int i = 0; i < 100; i++)
		this->_floor[i] = nullptr;
}

Character& Character::operator=(const Character& other){
	std::cout << "Character: Copy asignment called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			this->_inventory[i] = nullptr;
		}


		for (int i = 0; i < 4; i++)
		{
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
		}

		for (int i = 0; i < this->_floorIndex; i++)
		{
			if (this->_floor[i])
				delete this->_floor[i];
			this->_floor[i] = nullptr; 
		}
		this->_floorIndex = 0;
	}
	return *this;
}

std::string const & Character::getName() const{
	return this->_name;
}

void Character::equip(AMateria* m){
	if (!m)
		return;
	std::cout << "Character: " << getName() << " equip " << m->getType() << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i] && this->_inventory[i] != m)
		{
			this->_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx){
	if (idx < 0 || idx > 3 || !this->_inventory[idx])
		return;

	std::cout << "Character: " << getName() << " unequip slot [" << idx << "] with materia: "<< this->_inventory[idx]->getType() << std::endl;
	
	if (this->_floorIndex < 100)
		this->_floor[this->_floorIndex++] = this->_inventory[idx];
	this->_inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx > 3 || !this->_inventory[idx])
		return;
	
	std::cout << "Character: " << getName() << " use materia [" 
	<< this->_inventory[idx]->getType() << "] on " << target.getName() << std::endl;
	this->_inventory[idx]->use(target);
}
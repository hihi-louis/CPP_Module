/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 03:56:25 by tripham           #+#    #+#             */
/*   Updated: 2025/09/01 16:17:16 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource: Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_templates[i] = nullptr;
	}
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource: Default destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_templates[i])
			delete this->_templates[i];
		this->_templates[i] = nullptr;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other){
	std::cout << "MateriaSource: Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other._templates[i]){
			this->_templates[i] = other._templates[i]->clone();
		}
		else{
			this->_templates[i] = nullptr;
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other){
	std::cout << "MateriaSource: Copy assignment called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i) {
			if (this->_templates[i])
				delete this->_templates[i];
			if (other._templates[i])
				this->_templates[i] = other._templates[i]->clone();
			else
				this->_templates[i] = nullptr;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m){
	if (!m)
		return ;
	
	for (int i = 0; i < 4; i++)
	{
		if (!this->_templates[i]){
			this->_templates[i] = m->clone();
			std::cout << "Learned materia of type [" << m->getType() << "] in slot " << i << std::endl;
			delete m;
			return ;
		}
	}
	std::cout << "Inventory full, cannot learn [" << m->getType() << "]" << std::endl;
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_templates[i] && this->_templates[i]->getType() == type)
		{
			std::cout << "Cloning materia of type [" << type << "] from slot " << i << std::endl;
			return this->_templates[i]->clone();
		}
	}
	std::cout << "Unknown materia type: [" << type << "]" << std::endl;
	return nullptr;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 23:33:17 by tripham           #+#    #+#             */
/*   Updated: 2025/09/01 15:54:13 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter{
	public:
		Character();
		Character(std::string name);
		virtual ~Character();
		Character(const Character& other);
		Character& operator=(const Character& other);
		 
		std::string const & getName() const override;
		void equip(AMateria* m) override;
		void unequip(int idx) override;
		void use(int idx, ICharacter& target) override;
	private:
		std::string _name;
		AMateria *_inventory[4];
		AMateria *_floor[100];
		int 	  _floorIndex;
};
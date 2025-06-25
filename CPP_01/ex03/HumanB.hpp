/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:22:50 by tripham           #+#    #+#             */
/*   Updated: 2025/06/25 15:43:06 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB {
	public:
		HumanB(const std::string &name);
		~HumanB();
		
		void attack();
		void setWeapon(const Weapon &_weapon);
	private:
		const Weapon *_weapon;
		std::string _name;
};
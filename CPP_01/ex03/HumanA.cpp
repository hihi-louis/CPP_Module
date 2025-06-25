/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:41:09 by tripham           #+#    #+#             */
/*   Updated: 2025/06/24 15:54:46 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon): _name(name), _weapon(weapon){
    
}

HumanA::~HumanA(){}

void HumanA::attack() {
    if (this->_weapon)
    {
        
    }
}


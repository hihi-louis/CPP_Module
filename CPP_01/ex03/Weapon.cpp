/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:10:53 by tripham           #+#    #+#             */
/*   Updated: 2025/06/24 15:40:54 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

namespace myWeapon{

    Weapon::Weapon(const std::string &newType): _type(newType){}
    Weapon::~Weapon() {}
    
    const std::string &Weapon::getType() const {
        return (this->_type);
    }
    
    void Weapon::setType(const std::string newType) {
        this->_type = newType;   
    }
}
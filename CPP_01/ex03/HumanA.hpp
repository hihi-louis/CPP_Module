/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:43:27 by tripham           #+#    #+#             */
/*   Updated: 2025/06/25 15:23:06 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA {
    public:
        HumanA(const std::string &name, Weapon &weapon);
        ~HumanA();

        void attack();
    private:
        Weapon &_weapon;
        std::string _name;
};
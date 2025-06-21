/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:58:47 by tripham           #+#    #+#             */
/*   Updated: 2025/06/20 13:13:39 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Weapon {
    public:
        Weapon(const std::string &type);
        ~Weapon();
        
        const std::string &getType() const;
        void setType(const std::string newType);
    private:
        std::string _type;
};
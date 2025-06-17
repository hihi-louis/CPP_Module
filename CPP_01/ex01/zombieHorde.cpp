/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:18:53 by tripham           #+#    #+#             */
/*   Updated: 2025/06/17 19:57:35 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

namespace ZombieLouis {
	Zombie* zombieHorde( int N, std::string name )
	{
		if (N <= 0 || N > 10000)
		{
			std::cerr << "Invalid number of zombie." << std::endl;
			return (NULL);
		}
	
		Zombie* zHorde = NULL;
		
		try {
			zHorde = new Zombie[N];
		}
		catch(const std::bad_alloc&) {
			std::cerr << "Memory allocation failed for zombie horde." << std::endl;
			return NULL;
		}

		if (!zHorde)
			return NULL;

		for (int i = 0; i < N; ++i)
			zHorde[i].setName(name);
		
		return zHorde;
	}
}
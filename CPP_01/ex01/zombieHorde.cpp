/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:18:53 by tripham           #+#    #+#             */
/*   Updated: 2025/06/27 18:31:27 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

	Zombie* zombieHorde( int N, std::string name )
	{
		if (N <= 0 )//|| N > 10000)
		{
			std::cerr << "Invalid number of zombie." << std::endl;
			return (NULL);
		}
	
		Zombie* zHorde = NULL;
		
		try {
			zHorde = new Zombie[N];
		}
		catch(const std::bad_alloc& e) {
			std::cerr << "Memory allocation failed for zombie horde - " << e.what() << std::endl;
			return NULL;
		}

		if (!zHorde)
			return NULL;

		for (int i = 0; i < N; ++i)
			zHorde[i].setName(name);
		
		return zHorde;
	}
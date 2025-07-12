/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:18:53 by tripham           #+#    #+#             */
/*   Updated: 2025/07/12 13:50:02 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

	Zombie* zombieHorde( int N, std::string name )
	{
		if (N <= 0 || N > 10000)
		{
			std::cout << "Invalid number of zombie." << std::endl;
			return (nullptr);
		}
	
		Zombie* zHorde = nullptr;
		
		try {
			zHorde = new Zombie[N];
		}
		catch(const std::bad_alloc& e) {
			std::cout << "Memory allocation failed for zombie horde - " << e.what() << std::endl;
			return nullptr;
		}

		if (!zHorde)
			return nullptr;

		for (int i = 0; i < N; ++i)
			zHorde[i].setName(name);
		
		return zHorde;
	}
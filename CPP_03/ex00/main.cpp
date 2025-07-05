/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:28:08 by tripham           #+#    #+#             */
/*   Updated: 2025/07/05 14:32:19 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap player1("Taylor Swift");
	ClapTrap player2("Kaney West");
	ClapTrap player;

	std::cout << "\n--- ATTACK TEST ---" << std::endl;
	player1.attack("Kaney West");
	
	std::cout << "\n--- DAMAGE TEST ---" << std::endl;
	player2.takeDamage(4);
    player2.takeDamage(7);

	std::cout << "\n--- REPAIR TEST ---" << std::endl;
    player1.beRepaired(3); // Should work
    player2.beRepaired(5); // Should fail (destroyed)

	std::cout << "\n--- ENERGY DEPLETION TEST ---" << std::endl;
    for (int i = 0; i < 11; ++i)
        player1.attack("target");
	
	std::cout << "\n--- COPY TEST ---" << std::endl;
    ClapTrap player3(player1);
    player3.beRepaired(2);

	std::cout << "\n--- ASSIGNMENT TEST ---" << std::endl;
    player3 = player1;
    player3.attack("Cardi B");

	return 0;
}
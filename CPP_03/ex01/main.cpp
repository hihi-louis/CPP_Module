/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:28:08 by tripham           #+#    #+#             */
/*   Updated: 2025/07/07 01:29:12 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <new>

int main()
{
	ScavTrap player1("Ariana Grande");
	ScavTrap player2("Her best friend");
	ScavTrap player;

	std::cout << "\n--- ATTACK TEST ---" << std::endl;
	player1.attack("Her best friend");
	
	std::cout << "\n--- DAMAGE TEST ---" << std::endl;
	player2.takeDamage(40);
    player2.takeDamage(70);

	std::cout << "\n--- REPAIR TEST ---" << std::endl;
    player1.beRepaired(30); // Should work
    player2.beRepaired(500); // Should fail (destroyed)

	std::cout << "\n--- ENERGY DEPLETION TEST ---" << std::endl;
    for (int i = 0; i < 10; ++i)
        player1.attack("target");
	
	std::cout << "\n--- GuardGate TEST ---" << std::endl;
	player1.guardGate();
	player2.guardGate();
	
	std::cout << "\n--- COPY TEST ---" << std::endl;
    ScavTrap player3(player1);
    player3.beRepaired(2);

	std::cout << "\n--- ASSIGNMENT TEST ---" << std::endl;
    player3 = player1;
    player3.attack("Her best friend's husband");

	std::cout << "\n--- POLYMORPHIC TEST ---" << std::endl;
	try {
		ClapTrap* ptr = new ScavTrap("Polymorphic Ariana");
		ptr->attack("target from pointer");
		delete ptr;
	} catch (const std::bad_alloc& e)
	{
		std::cerr << "Allocation failed: " << e.what() << std::endl;
	} 
	
	return 0;
}
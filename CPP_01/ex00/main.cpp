/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:33:33 by tripham           #+#    #+#             */
/*   Updated: 2025/06/17 18:14:33 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
	Zombie* zombieOnHeap = newZombie("ZombieOnHeap");
	if (zombieOnHeap == NULL) {
		std::cerr << "Failed to create heap allocation zombie." << std::endl;
		return 1;
	}
	zombieOnHeap->announce();
	delete zombieOnHeap;
	randomChump("ZombieOnStack");
	return 0;
}
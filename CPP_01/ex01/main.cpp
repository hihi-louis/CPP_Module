/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:07:07 by tripham           #+#    #+#             */
/*   Updated: 2025/06/17 19:34:22 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
using namespace ZombieLouis;

void testHord(int N, const std::string& name)
{
	std::cout << "Test zombie: " << N << " - " << name << std::endl;

	Zombie* horde = zombieHorde(N, name);
	if (!horde)
	{
		std::cerr << "Failed to create horde." << std::endl;
		return;
	}
	for (int i = 0; i < N; ++i)
			std::cout << "[" << i + 1 << "] ", horde[i].announce();
	delete[] horde;
}
int main()
{
	testHord(5, "Positive num");
	testHord(0, "zero");
	testHord(-3, "Negative num");
	testHord(10, "Too Many");
	return 0;
}
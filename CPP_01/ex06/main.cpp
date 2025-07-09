/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:58:12 by tripham           #+#    #+#             */
/*   Updated: 2025/07/09 04:50:11 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int getLevelIndex(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			return i;
	}
	return -1;
}

int main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: Invalid input." << std::endl;
		return EXIT_FAILURE;
	}
	Harl harl;
	int index = getLevelIndex(av[1]);

	switch (index)
	{
		case 0:
			harl.complain("DEBUG");
			[[fallthrough]];
		case 1:
			harl.complain("INFO");
			[[fallthrough]];
		case 2:
			harl.complain("WARNING");
			[[fallthrough]];
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "Probably complaining about insignificant problems." << std::endl;
	}
	return 0;
}
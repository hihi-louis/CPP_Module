/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:54:50 by tripham           #+#    #+#             */
/*   Updated: 2025/07/25 15:19:42 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex04.hpp"
#include <cstdlib>


int main (int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Error: Invalid input." << std::endl;
		return EXIT_FAILURE;
	}
	const std::string inputFile = av[1];
	const std::string s1 = av[2];
	const std::string s2 = av[3];
	
	if (s1.empty())
	{
		std::cout << "Error: s1 must not be empty" << std::endl;
		return EXIT_FAILURE;
	}
	replacer rep(inputFile, s1, s2);
	int result = rep.process();
	if (result)
	{
		if (result == -1)
			return EXIT_FAILURE;
		std::cout << "Error: Replacement failed." << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << "Replacement completed. Output file: " << inputFile + ".replace" << std::endl;
	return EXIT_SUCCESS;
}
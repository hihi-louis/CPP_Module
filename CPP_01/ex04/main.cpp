/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:54:50 by tripham           #+#    #+#             */
/*   Updated: 2025/06/27 02:33:35 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex04.hpp"

int main (int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Error: Invalid input." << std::endl;
		return EXIT_FAILURE;
	}
	const std::string inputFile = av[1];
	const std::string s1 = av[2];
	const std::string s2 = av[3];
	
	if (s1.empty())
	{
		std::cerr << "Error: s1 must not be empty" << std::endl;
		return EXIT_FAILURE;
	}
	replacer rep(inputFile, s1, s2);
	int result = rep.process();
	if (result)
	{
		if (result == -1 || result == -2)
			return EXIT_FAILURE;
		std::cerr << "Error: Replacement failed." << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << "Replacement completed. Output file: " << inputFile + ".replace" << std::endl;
	return EXIT_SUCCESS;
}
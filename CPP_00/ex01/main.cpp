/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:30:46 by tripham           #+#    #+#             */
/*   Updated: 2025/06/27 17:34:59 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <csignal>

static void handleSigint(int signum)
{
	std::cout << "\n[!] Caught signal " << signum << " (Ctrl+C). Exiting gracefully..." << std::endl;
	std::exit(signum);
}

int	main()
{
	signal(SIGINT, handleSigint);
	PhoneBook PhoneBook;
	std::string cmd;

	std::cout << "Welcome to the 80s PhoneBook!" << std::endl;
	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
		{
			std::cout << "EOF detected. Exitting" << std::endl;
			break ;	
		}

		if (!cmd.compare("ADD"))
			PhoneBook.add();
		else if (!cmd.compare("SEARCH"))
			PhoneBook.search();
		else if (!cmd.compare("EXIT")) 
		{
			std::cout << "Bye Bye" << std::endl;
			break;
		}
		else
			std::cout << "Unknown command. Please try again" << std::endl;
	}
	return (0);
}
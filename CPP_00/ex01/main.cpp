/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:30:46 by tripham           #+#    #+#             */
/*   Updated: 2025/08/22 21:28:10 by tripham          ###   ########.fr       */
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

int main()
{
    signal(SIGINT, handleSigint);
    PhoneBook PhoneBook;
    std::string cmd;

    std::cout << "Welcome to the 80s PhoneBook!" << std::endl;
    while (true)
    {
		if (!std::getline(std::cin, cmd))
        {
			std::cin.clear(); // clear trạng thái EOF
            // không in gì cả, chỉ quay lại prompt
            continue;
        }
		
		std::cout << "Enter a command (ADD, SEARCH, EXIT): " << std::flush;
        if (cmd == "ADD")
            PhoneBook.add();
        else if (cmd == "SEARCH")
            PhoneBook.search();
        else if (cmd == "EXIT")
        {
            std::cout << "Bye Bye" << std::endl;
            break;
        }
        else
            std::cout << "Unknown command. Please try again" << std::endl;

    }
    return 0;
}
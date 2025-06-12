/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:27:12 by tripham           #+#    #+#             */
/*   Updated: 2025/06/12 23:55:26 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
PhoneBook::PhoneBook(){
	_id = 0;
	_idCount = 0;
}

std::string userInput(std::string input)
{
	std::string info; /*same as std::string info = "";*/
	if (std::cin.eof())
		return (info);
	std::cout << info << std::endl;
	std::getline(std::cin, info);
	return (info);
}

void PhoneBook::add()
{
	std::string firstName = userInput("Your First Name: ");
	if (firstName.empty())
		std::cout << "Empty Input, Please Try Again" << std::endl;
	std::string lastName = userInput("Your Last Name: ");
	if (lastName.empty())
		std::cout << "Empty Input, Please Try Again" << std::endl;
	std::string nickName = userInput("Your Nick Name: ");
	if (nickName.empty())
		std::cout << "Empty Input, Please Try Again" << std::endl;
	std::string phoneNumber = userInput("Your Phone Number: ");
	if (phoneNumber.empty())
		std::cout << "Empty Input, Please Try Again" << std::endl;
	std::string darkestSecret = userInput("Your Darkest Secret: ");
	if (darkestSecret.empty())
		std::cout << "Empty Input, Please Try Again" << std::endl;
	
	if (!firstName.empty() && !lastName.empty() && !nickName.empty() && !phoneNumber.empty() && !darkestSecret.empty())
	{
		_id = (_id == 8) ? 0 : _id;
		
	}
}

PhoneBook::~PhoneBook(){}

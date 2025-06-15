/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:27:12 by tripham           #+#    #+#             */
/*   Updated: 2025/06/15 15:27:30 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(){
	_id = 0;
	_idCount = 0;
}

std::string userInput(const std::string& prompt)
{
	std::string input; /*same as std::string info = "";*/
	while (1)
	{
		if (std::cin.eof())
			return "";
		std::cout << prompt;
		std::getline(std::cin, input);
		if (!input.empty())
			return input;
		std::cout << "Empty input! Please try again.\n";
	}
}

void PhoneBook::add()
{
	std::string firstName = userInput("Your First Name: ");
	std::string lastName = userInput("Your Last Name: ");
	std::string nickName = userInput("Your Nick Name: ");
	std::string phoneNumber = userInput("Your Phone Number: ");
	std::string darkestSecret = userInput("Your Darkest Secret: ");
	
	if (firstName.empty() && lastName.empty() && nickName.empty() && phoneNumber.empty() && darkestSecret.empty())
	{
		std::cout << "Cancelled or input error.\n";
		return;
	}
	if (_id == 8)
		_id = 0;
	Contact newUser(_id ,firstName, lastName, nickName, phoneNumber, darkestSecret);
	_list[_id] = newUser;
	_id++;
	_idCount++;
}

void PhoneBook::search() const
{
	std::string id_request;
	int index;

	if (_idCount < 1)
	{
		std::cout << "Empty PhoneBook" << std::endl;
		return ;
	}
	displayTableHeader();
	for (int i = 0; i < _idCount; i++)
		_list[i].displayTableInfo();
	id_request = userInput("Search Person At Index: ");
	index = id_request.at(0) - '0';
	if (id_request.length() != 1 || index > 7 || index < 0 || index + 1 > _idCount)
	{
		std::cout << "Wrong Input" << std::endl;
		return ;
	}
	_list[index].displayFullInfo();
}
PhoneBook::~PhoneBook(){}

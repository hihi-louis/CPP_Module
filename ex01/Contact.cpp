/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:15:25 by tripham           #+#    #+#             */
/*   Updated: 2025/06/15 15:27:15 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){}

Contact::Contact(int			  id,
				const std::string firstName,
				const std::string lastName,
				const std::string nickName,
				const std::string phoneNumber,
				const std::string darkestSecret)
				:_id(id),
				_firstName(firstName),
				_lastName(lastName),
	 			_nickName(nickName),
				_phoneNumber(phoneNumber),
	  			_darkestSecret(darkestSecret){}
Contact::~Contact(){}

std::string ft_truncate(std::string str)
{
	return (str.length() > 10 ? (str.substr(0, 9) + '.') : str);
}

void displayTableHeader()
{
	std::cout << std::string(44, '_') << std::endl;
	std::cout << std::setw(10) << "ID" << '|';
	std::cout << std::setw(10) << "First Name" << '|';
	std::cout << std::setw(10) << "Last Name" << '|';
	std::cout << std::setw(10) << "Nick Name" << '|' << std::endl;
}

void Contact::displayTableInfo() const
{
	std::cout << std::setw(10) << _id << '|';
	std::cout << std::setw(10) << ft_truncate(_firstName) << '|';
	std::cout << std::setw(10) << ft_truncate(_lastName) << '|';
	std::cout << std::setw(10) << ft_truncate(_nickName) << '|' << std::endl;
}

void Contact::displayFullInfo() const
{
	std::cout << "ID: " << _id << std::endl;
	std::cout << "First Name: " << _firstName << std::endl;
	std::cout << "Last Name: " << _lastName << std::endl;
	std::cout << "Nick Name: " << _nickName << std::endl;
	std::cout << "Phone Number: " << _phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}
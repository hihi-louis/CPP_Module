/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:34:45 by tripham           #+#    #+#             */
/*   Updated: 2025/06/15 16:00:30 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
 # define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
	public:
		PhoneBook();
		
		void add();
		void search() const;
		
		~PhoneBook();
	private:
		Contact _list[8];
		int _id;
		int _idCount;
};

std::string userInput(const std::string& prompt);
#endif
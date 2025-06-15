/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:15:39 by tripham           #+#    #+#             */
/*   Updated: 2025/06/13 20:34:59 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact{
	public:
		Contact(); /*Default constructor*/
		Contact (
				const int					id,
				const std::string firstName,
				const std::string lastName,
				const std::string nickName,
				const std::string phoneNumber,
				const std::string darkestSecret); /*Constructor with full info*/
		~Contact();  /*Default destructor*/
		
		void   displayTableInfo() const;
		void   displayFullInfo() const; /*Print details of info*/
	private:
		int			_id;
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

	void displayTableHeader(); /*Print table info*/
#endif
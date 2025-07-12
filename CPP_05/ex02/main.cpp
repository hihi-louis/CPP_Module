/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:08:47 by tripham           #+#    #+#             */
/*   Updated: 2025/07/12 18:09:13 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

int main()
{
	try {
		ShrubberyCreationForm a("Louis");
		Bureaucrat b("haha", 30);

		a.beSigned(b);

		a.execute(b);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try{
		Ro
	}
	return 0;
}
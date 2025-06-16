/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 21:31:24 by tripham           #+#    #+#             */
/*   Updated: 2025/06/08 22:49:18 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string arg(argv[i]);				  /*convert C-string to std::string to use .lenght() .at()*/
			for (size_t j = 0; j < arg.length(); j++) /*arg.length return unsigned long, that's why j must be decleard by size_t*/
			{
				char up_case = static_cast<char>(std::toupper(arg.at(j))); /*std::toupper return int type, so it must be convert to char for correctly printing*/
				std::cout << up_case;
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
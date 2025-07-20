/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:25:02 by tripham           #+#    #+#             */
/*   Updated: 2025/07/20 12:17:05 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	try
	{
		Zombie	*newzb = new Zombie(name);
		return (newzb);
	}
	catch (std::bad_alloc &error)
	{
		std::cerr << "Memory allocation failed: " << error.what() << std::endl;
		return (nullptr);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 02:58:44 by tripham           #+#    #+#             */
/*   Updated: 2025/07/08 15:45:03 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#define LOG(message) std::cout << "\033[38;5;218m" << message << "\033[0m" << std::endl

class Brain{
	public:
		Brain();
		~Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain &other);

		void setIdea(int index, const std::string& idea);
		std::string getIdea(int index) const;
	private:
		std::string _ideas[100];
};
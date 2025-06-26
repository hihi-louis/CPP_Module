/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:20:59 by tripham           #+#    #+#             */
/*   Updated: 2025/06/27 02:13:26 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

class replacer{
	public:
		replacer(const std::string& infile, const std::string& s1, const std::string& s2);
		~replacer();
		
		int process();
	private:
		std::string _infile;
		std::string _s1;
		std::string _s2;
	private:
		std::string copiedLine(const std::string& line) const;
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:18:51 by tripham           #+#    #+#             */
/*   Updated: 2025/07/20 12:30:43 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex04.hpp"

replacer::replacer(const std::string& infile, const std::string& s1, const std::string& s2)
	: _infile(infile), _s1(s1), _s2(s2) {}

replacer::~replacer() {}

std::string replacer::copiedLine(const std::string& line) const
{
	if (_s1.empty())
		return line;
	std::string newLine;
	size_t position = 0;
	size_t foundPosition;

	while ((foundPosition = line.find(_s1, position)) != std::string::npos)
	{
		newLine.append(line, position, foundPosition - position);
		
		newLine += _s2;
		position = foundPosition + _s1.length();
	}
	newLine.append(line, position, std::string::npos);
	return newLine;
}

// int replacer::process()
// {
// 	std::ifstream inputFile(_infile.c_str());
// 	if (!inputFile.is_open())
// 	{
// 		std::cout << "Error: Could not open input file." << std::endl;
// 		return -1;
// 	}
// 	std::ofstream outputFile((_infile + ".replace").c_str());
// 	if (!outputFile.is_open())
// 	{
// 		std::cout << "Error: Could not create output file." << std::endl;
// 		inputFile.close();
// 		return -2;
// 	}
// 	std::string line;
// 	while (std::getline(inputFile, line))
// 	{
// 		std::string res = copiedLine(line);
// 		outputFile << res << std::endl;
// 	}
// 	if (inputFile.bad())
// 	{
// 		std::cout << "Error: I/O error while reading." << std::endl;
// 	}
// 	inputFile.close();
// 	outputFile.close();
// 	return 0;
// }

int replacer::process()
{
	std::ifstream inputFile(_infile.c_str());
	if (!inputFile.is_open())
	{
		std::cout << "Error: Could not open input file." << std::endl;
		return -1;
	}

	std::ofstream outputFile((_infile + ".replace").c_str());
	if (!outputFile.is_open())
	{
		std::cout << "Error: Could not create output file." << std::endl;
		inputFile.close();
		return -2;
	}

	std::string line;
	while (true)
	{
		if (!std::getline(inputFile, line))
		{
			if (inputFile.eof())
				break; // Đọc xong hết file => OK
			else if (inputFile.fail())
			{
				std::cout << "Error: Failed to read a line (possibly malformed input)." << std::endl;
				inputFile.close();
				outputFile.close();
				return -3;
			}
			else if (inputFile.bad())
			{
				std::cout << "Error: I/O error while reading from file." << std::endl;
				inputFile.close();
				outputFile.close();
				return -4;
			}
			else
			{
				std::cout << "Error: Unknown error while reading from file." << std::endl;
				inputFile.close();
				outputFile.close();
				return -5;
			}
		}

		std::string res = copiedLine(line);
		outputFile << res << std::endl;
	}

	inputFile.close();
	outputFile.close();
	return 0;
}
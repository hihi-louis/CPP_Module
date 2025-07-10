/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:34:32 by tripham           #+#    #+#             */
/*   Updated: 2025/07/11 02:55:40 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	SUCCESS("========== Bureaucrat Tests ==========");
	INFO("Test 1: Too high grade");
	
	try
	{
		Bureaucrat a("Harry Portter", 0);
		std::cout << a;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		EXCEPTION(e.what());
	}
	
	INFO("Test 2: Success");
	
	try
	{
		Bureaucrat A("Harry Portter", 5);
		std::cout << A << std::endl;
	}
	catch(const std::exception& e)
	{
		EXCEPTION(e.what());
	}
	
	INFO("Test 3: Decrement cases");
	
	Bureaucrat b("Doraemon", 149);
	try
	{
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
	}
	catch(const std::exception& e)
	{
		EXCEPTION(e.what());
	}

	INFO("Test 4: Increment cases");
		Bureaucrat c("Sailor Moon", 1);
	try
	{
		std::cout << c;
		std::cout << std::endl;
		c.incrementGrade();
		c.incrementGrade();
	}
	catch(const std::exception& e)
	{
		EXCEPTION(e.what());
	}

	SUCCESS("========== Form Tests ==========");
	
	INFO("Test 1: Grade too high to sign");

	try{
		Form a("Too high grade to sign form", 0, 10);
	}
	catch(const std::exception& e)
	{
		EXCEPTION(e.what());
	}

	INFO("Test 2: Grade too low to execute");

	try{
		Form b("Too low execute grade to sign form", 150, 151);
	}
	catch(const std::exception& e)
	{
		EXCEPTION(e.what());
	}

	INFO("Test 3: Valid Form and Print out");
	try{
		Form c("Home Contract", 50, 30);
		std::cout << c << std::endl;
	}
	catch(const std::exception& e)
	{
		EXCEPTION(e.what());
	}

	INFO("Test 4: Successfully sign");

	try{
		Form e("Car contract", 70, 5);
		Bureaucrat f("Louis", 45);
		f.signForm(e);
		std::cout << e << std::endl;
	}
	catch(const std::exception& e)
	{
		EXCEPTION(e.what());
	}

	INFO("Test 5: Unsuccessfully sign");

		try{
		Form g("Working contract", 70, 5);
		Bureaucrat h("Louis", 75);
		h.signForm(g);
		std::cout << g << std::endl;
	}
	catch(const std::exception& e)
	{
		EXCEPTION(e.what());
	}
	
	return 0;
}
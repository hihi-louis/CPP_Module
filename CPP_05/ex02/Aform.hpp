/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 03:20:31 by tripham           #+#    #+#             */
/*   Updated: 2025/07/11 13:09:52 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Bureaucrat;

class Aform{
	public:
		Aform(std::string name, int gradeTosign, int gradeToExecute);
		~Aform();
		Aform(const Aform& other);
		Aform& operator=(const Aform& other);
		
		std::string getName() const;
		bool		getIssigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		bool 		execute(Bureaucrat const & executor) const;
		
		
}
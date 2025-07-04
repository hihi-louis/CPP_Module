/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 04:31:11 by tripham           #+#    #+#             */
/*   Updated: 2025/07/04 04:36:09 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
	Point a(12, 11);
	Point b(24, 3);
	Point c(28, 8);
	Point point(10, 4);

	bool flag = bsp(a, b, c, point);
	std::cout <<  (flag ? "Inside" : "Outside") << std::endl;
	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 04:17:29 by tripham           #+#    #+#             */
/*   Updated: 2025/07/04 04:28:36 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed area(Point const& a, Point const& b, Point const& c)
{	// (Ax(By - Cy) + Bx(Cy - Ay) + Cx(Ay - By)) / 2
	Fixed result = a.getX() * (b.getY() - c.getY()) +
				 b.getX() * (c.getY() - a.getY()) +
				 c.getX() * (a.getY() - b.getY());
	return result < Fixed(0) ? result * Fixed(-1) : result;
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
	Fixed total = area(a, b, c);
	Fixed triangle1 = area(point, a, b);
	Fixed triangle2 = area(point, b, c);
	Fixed triangle3 = area(point, c, a);

	if (triangle1 == Fixed(0) || triangle2 == Fixed(0) || triangle3 == Fixed(0))
		return false;

	return (triangle1 + triangle2 + triangle3) == total;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 03:53:23 by tripham           #+#    #+#             */
/*   Updated: 2025/08/03 19:33:43 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0){}
Point::~Point(){}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point::Point(const Point& other): _x(other._x), _y(other._y) {}

Fixed Point::getX(void) const {return this->_x;}
Fixed Point::getY(void) const {return this->_y;}

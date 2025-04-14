/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:25:01 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/14 14:11:45 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Point::Point(void)
{
	this->_x = Fixed(0);
	this->_y = Fixed(0);
}

Point::Point(const Fixed & x, const Fixed & y)
{
	this->_x = x;
	this->_y = y;
}

Point::Point(const Point & src)
{
	*this = src;
}

Point & Point::operator = (const Point & rhs)
{
	if (this != &rhs)
	{
		this->_x = rhs.getFixedX();
		this->_y = rhs.getFixedY();
	}
	return (*this);
}

Point::~Point(void)
{
}

Fixed	Point::getFixedX(void) const
{
	return (this->_x);
}

Fixed	Point::getFixedY(void) const 
{
	return (this->_y);
}

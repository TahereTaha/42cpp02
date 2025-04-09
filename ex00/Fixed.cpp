/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:00:22 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/09 08:23:41 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called." << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed(const Fixed & src)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = src;	//	this is using the copy assigment
}

Fixed::~Fixed(void)
{
	std::cout << "Destructior called." << std::endl;
}

Fixed & Fixed::operator=(const Fixed & rhs)	// rhs is the thing to the right of a assigment operator.
{
	std::cout << "Assigment operator called." << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
//		*this = rhs;	// this can't be like that because the copy assigment is called in bucle.
	return (*this);
}

int		Fixed::getRawBits(void) const 
{
	std::cout << "getRawBits member function called." << std::endl;
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called." << std::endl;
	this->_fixedPointValue = raw;
}

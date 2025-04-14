/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:00:22 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/14 17:11:10 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <bitset>

//	constructors.
Fixed::Fixed(void)
{
//	std::cout << "Default constructor called." << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed(const Fixed & src)
{
//	std::cout << "Copy constructor called." << std::endl;
	*this = src;	//	this is using the copy assigment
}

Fixed::Fixed(const int num)
{
	this->setRawBits(num << this->_fractionalBits);
}

static float	get_value_on_index(const int index)
{
	int		i;
	float	value;

	if (index >= 0)
		return ((float)(1 << index));
	value = 1;
	i = index;
	while (i != 0)
	{
		value /= 2;
		i++;
	}
	return (value);
}

static int	get_twos_complement(int num)
{
	num = (num ^ ((int)-1)) + 1;
	return (num);
}

int	Fixed::get_integral_raw_bits(float integral, float fractional) const
{
	int	raw_bits;

	if (fractional < 0.0)
		raw_bits = (((int)integral) - 1) << this->_fractionalBits;
	else
		raw_bits = ((int)integral) << this->_fractionalBits;
	return (raw_bits);
}

static	int	get_mask(int bite_size)
{
	int	mask;

	mask = (1 << bite_size) - 1;
	return (mask);
}

int	Fixed::get_fractional_raw_bits(float fractional) const
{
	float	value_on_index;
	int		raw_bits;
	int		i;
	int		negative;

	negative = 0;
	if (fractional < 0.0)
		negative = 1;
	fractional = fabs(fractional);
	raw_bits = 0;
	//		the index to the first fractional bit.
	i = this->_fractionalBits - 1;
	while (i >= 0 && fractional != 0)
	{
		value_on_index = get_value_on_index(i - this->_fractionalBits);
		if (fractional >= value_on_index)
		{
			raw_bits |= 1 << i;
			fractional -= value_on_index;
		}
		i--;
	}
	if (negative)
	{
		raw_bits = get_twos_complement(raw_bits);
		raw_bits = raw_bits & get_mask(this->_fractionalBits);
	}
	return (raw_bits);
}

Fixed::Fixed(const float num)
{
	float	fractional;
	float	integral;
	int		raw_bits;

	fractional = std::modf(num, &integral);
	raw_bits = this->get_integral_raw_bits(integral, fractional);
	raw_bits |= this->get_fractional_raw_bits(fractional);
	this->setRawBits(raw_bits);
}

//	destructor.
Fixed::~Fixed(void)
{
//	std::cout << "Destructior called." << std::endl;
}

//	copy assigment.
Fixed & Fixed::operator=(const Fixed & rhs)	// rhs is the thing to the right of a assigment operator.
{
//	std::cout << "Assigment operator called." << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
//		*this = rhs;	// this can't be like that because the copy assigment is called in bucle.
	return (*this);
}

//	some operator overloadings.

bool	Fixed::operator > (const Fixed & src) const
{
	return (this->toFloat() > src.toFloat());
}

bool	Fixed::operator < (const Fixed & src) const
{
	return (this->toFloat() < src.toFloat());
}

bool	Fixed::operator >= (const Fixed & src) const
{
	return (this->toFloat() >= src.toFloat());
}

bool	Fixed::operator <= (const Fixed & src) const
{
	return (this->toFloat() <= src.toFloat());
}

bool	Fixed::operator == (const Fixed & src) const
{
	return (this->toFloat() == src.toFloat());
}

bool	Fixed::operator != (const Fixed & src) const
{
	return (this->toFloat() != src.toFloat());
}

Fixed & Fixed::operator += (const Fixed & rhs)
{
	Fixed	res(this->toFloat() + rhs.toFloat());
	*this = res;
	return (*this);
}

Fixed & Fixed::operator -= (const Fixed & rhs)
{
	Fixed	res(this->toFloat() - rhs.toFloat());
	*this = res;
	return (*this);
}

Fixed	Fixed::operator + (const Fixed & src)
{
	Fixed	res(this->toFloat() + src.toFloat());
	return (res);
}

Fixed	Fixed::operator - (const Fixed & src)
{
	Fixed	res(this->toFloat() - src.toFloat());
	return (res);
}

Fixed	Fixed::operator * (const Fixed & src)
{
	Fixed	res(this->toFloat() * src.toFloat());
	return (res);
}

Fixed	Fixed::operator / (const Fixed & src)
{
	Fixed	res(this->toFloat() / src.toFloat());
	return (res);
}

Fixed & Fixed::operator ++ (void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator ++ (int)
{
	Fixed	ret(*this);

	this->setRawBits(this->getRawBits() + 1);
	return (ret);
}

Fixed & Fixed::operator -- (void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator -- (int)
{
	Fixed	ret(*this);

	this->setRawBits(this->getRawBits() - 1);
	return (ret);
}


//	methods.

int	Fixed::toInt(void) const
{
	int	number;

	number = this->_fixedPointValue >> this->_fractionalBits;
	if (number & (1 << (this->_fractionalBits - 1)))
		number |= ((int)-1) << (sizeof(this->_fixedPointValue) * 8 - this->_fractionalBits);
	if (number < 0 && (0 != (this->_fixedPointValue << (sizeof(this->_fixedPointValue) * 8 - this->_fractionalBits))))
		number++;
	return (number);
}

float	Fixed::toFloat(void) const
{
	float	number;
	int		i;

	number = this->toInt();
	if (this->_fixedPointValue >> (sizeof(this->_fixedPointValue) * 8 - 1))
		number--;
	i = this->_fractionalBits - 1;
	while (i >= 0)
	{
		if (this->_fixedPointValue & (1 << i))
			number += get_value_on_index(i - this->_fractionalBits);
		i--;
	}
	return (number);
}

int		Fixed::getRawBits(void) const 
{
//	std::cout << "getRawBits member function called." << std::endl;
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
//	std::cout << "setRawBits member function called." << std::endl;
	this->_fixedPointValue = raw;
}

Fixed & Fixed::min(Fixed & src1, Fixed & src2)
{
	if (src1 < src2)
		return (src1);
	return (src2);
}

const Fixed & Fixed::min(const Fixed & src1, const Fixed & src2)
{
	if (src1 < src2)
		return (src1);
	return (src2);
}

Fixed & Fixed::max(Fixed & src1, Fixed & src2)
{
	if (src1 > src2)
		return (src1);
	return (src2);
}

const Fixed & Fixed::max(const Fixed & src1, const Fixed & src2)
{
	if (src1 > src2)
		return (src1);
	return (src2);
}

//	overloading of the << to ostream.

std::ostream & operator << (std::ostream &out_s, const Fixed &src)
{
	out_s << src.toFloat();
	return (out_s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:31:19 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/29 18:49:12 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
		
		int	get_integral_raw_bits(float integral, float fractional) const ;
		int	get_fractional_raw_bits(float fractional) const ;

	public:
		Fixed(void);
		Fixed(const Fixed & src);	//	this is for not having to use more memory than needed.
		Fixed(const int num);
		Fixed(const float num);
		~Fixed(void);
		Fixed & operator=(const Fixed & src);
		
		bool	operator > (const Fixed & src) const;
		bool	operator < (const Fixed & src) const;
		bool	operator >= (const Fixed & src) const;
		bool	operator <= (const Fixed & src) const;
		bool	operator == (const Fixed & src) const;
		bool	operator != (const Fixed & src) const;
		
		Fixed	operator + (const Fixed & src);
		Fixed	operator - (const Fixed & src);
		Fixed	operator * (const Fixed & src);
		Fixed	operator / (const Fixed & src);
		
		Fixed	&operator ++ (void);
		Fixed	operator ++ (int);
		Fixed	&operator -- (void);
		Fixed	operator -- (int);

		int		isNegative(void) const ;
		int		toInt(void) const ;
		float	toFloat(void) const ;
		int		getRawBits(void) const ;
		void	setRawBits(int const raw);
		
		static	Fixed &min(Fixed & src1, Fixed & src2);
		static	const Fixed &min(const Fixed & src1, const Fixed & src2);
		static	Fixed &max(Fixed & src1, Fixed & src2);
		static	const Fixed &max(const Fixed & src1, const Fixed & src2);
};

std::ostream & operator << (std::ostream &out_s, const Fixed &src);

#endif

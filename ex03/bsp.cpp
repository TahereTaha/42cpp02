/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:57:19 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/14 17:33:56 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include "Point.hpp"
# include "bsp.hpp"
# include <iostream>

//	thanks to this video for helping me with this exercice.
//	https://www.youtube.com/watch?v=HYAgJN3x4GA

bool	bsp(const Point & a, const Point & b, const Point & c, const Point & point)
{
	Fixed	numerator;
	Fixed	denominator;
	Fixed	w1;
	Fixed	w2;

	numerator = a.getFixedX() * (c.getFixedY() - a.getFixedY());
	numerator += (point.getFixedY() - a.getFixedY()) * (c.getFixedX() - a.getFixedX());
	numerator -= point.getFixedX() * (c.getFixedY() - a.getFixedY());
	denominator = (b.getFixedY() - a.getFixedY()) * (c.getFixedX() - a.getFixedX());
	denominator -= (b.getFixedX() - a.getFixedX()) * (c.getFixedY() - a.getFixedY());
	w1 = numerator / denominator;
	numerator = point.getFixedY() - a.getFixedY();
	numerator -= w1 * (b.getFixedY() - a.getFixedY());
	denominator = c.getFixedY() - a.getFixedY();
	w2 = numerator / denominator;
	if (w1 < 0 || w2 < 0 || ((w1 + w2) > Fixed(1.0f) ))
		return (0);
	return (1);
}

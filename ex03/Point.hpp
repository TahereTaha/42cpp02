/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:26:03 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/14 14:10:19 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed	_x;
		Fixed	_y;

	public:
		Point(void);
		Point(const Fixed & x, const Fixed & y);
		Point(const Point & src);
		Point & operator=(const Point & src);
		~Point(void);

		Fixed	getFixedX(void) const ;
		Fixed	getFixedY(void) const ;
};

#endif


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:24:52 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/14 17:33:28 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.hpp"
#include <iostream>

int		main(void)
{
	Point	a(Fixed(0), Fixed(0));
	Point	b(Fixed(100), Fixed(0));
	Point	c(Fixed(0), Fixed(100));
	Point	point1(Fixed(10), Fixed(10));
	Point	point2(Fixed(10), Fixed(20));
	Point	point3(Fixed(40), Fixed(40));
	Point	point4(Fixed(60), Fixed(50));
	Point	point5(Fixed(1000), Fixed(500));

	std::cout << "the point 1 is: " << bsp(a, b, c, point1) << std::endl;
	std::cout << "the point 2 is: " << bsp(a, b, c, point2) << std::endl;
	std::cout << "the point 3 is: " << bsp(a, b, c, point3) << std::endl;
	std::cout << "the point 4 is: " << bsp(a, b, c, point4) << std::endl;
	std::cout << "the point 4 is: " << bsp(a, b, c, point5) << std::endl;
	return (0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:24:52 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/29 19:06:53 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.hpp"
#include <iostream>

int		main(void)
{
	Point	a(Fixed(0), Fixed(0));
	std::cout << "point a: 0, 0" << std::endl;
	Point	b(Fixed(100), Fixed(0));
	std::cout << "point b: 100, 0" << std::endl;
	Point	c(Fixed(0), Fixed(100));
	std::cout << "point c: 0, 100" << std::endl;
	
	Point	point1(Fixed(10), Fixed(10));
	std::cout << "point 1: 10, 10" << std::endl;
	Point	point2(Fixed(10), Fixed(20));
	std::cout << "point 2: 10, 20" << std::endl;
	Point	point3(Fixed(40), Fixed(40));
	std::cout << "point 3: 40, 40" << std::endl;
	Point	point4(Fixed(60), Fixed(50));
	std::cout << "point 4: 60, 50" << std::endl;
	Point	point5(Fixed(1000), Fixed(500));
	std::cout << "point 5: 1000, 500" << std::endl;

	std::cout << "the point 1 is: " << bsp(a, b, c, point1) << std::endl;
	std::cout << "the point 2 is: " << bsp(a, b, c, point2) << std::endl;
	std::cout << "the point 3 is: " << bsp(a, b, c, point3) << std::endl;
	std::cout << "the point 4 is: " << bsp(a, b, c, point4) << std::endl;
	std::cout << "the point 4 is: " << bsp(a, b, c, point5) << std::endl;
	return (0);
}


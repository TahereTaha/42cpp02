/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:24:52 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/26 15:21:47 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <bitset>

//int	main(void)
//{
//	// printing the number normaly.
//	{
//		Fixed const	a(1);
//		Fixed const	b(1.5f);
//		Fixed const	c(2);
//	
//		std::cout << a.getRawBits() << std::endl;
//		std::cout << b.getRawBits() << std::endl;
//		std::cout << c.getRawBits() << std::endl;
//	}
//	// printing the number on binary.
//	{
//		Fixed const	a(1);
//		Fixed const	b(1.5f);
//		Fixed const	c(2);
//		
//		std::cout << std::bitset<sizeof(int) * 8>(a.getRawBits()) << std::endl;
//		std::cout << std::bitset<sizeof(int) * 8>(b.getRawBits()) << std::endl;
//		std::cout << std::bitset<sizeof(int) * 8>(c.getRawBits()) << std::endl;
//	}
//	return (0);
//}

//int	main(void)
//{
//	Fixed a(-7.75f);
//	Fixed b(-2.25f);
//	Fixed c(-3.5f);
//
//	std::cout << std::bitset<sizeof(int) * 8>(a.getRawBits()) << std::endl;
//	std::cout << a.toFloat() << std::endl;
//	std::cout << a.toInt() << std::endl;
//	
//	std::cout << std::bitset<sizeof(int) * 8>(b.getRawBits()) << std::endl;
//	std::cout << b.toFloat() << std::endl;
//	std::cout << b.toInt() << std::endl;
//	
//	std::cout << std::bitset<sizeof(int) * 8>(c.getRawBits()) << std::endl;
//	std::cout << c.toFloat() << std::endl;
//	std::cout << c.toInt() << std::endl;
//}

//int		main()
//{
//	Fixed	const c(-1);
//	Fixed	const a(-2.0f);
//	Fixed	const b(-2);
//
//	std::cout << std::bitset<sizeof(int) * 8>(c.getRawBits()) << std::endl;
//	std::cout << std::bitset<sizeof(int) * 8>(a.getRawBits()) << std::endl;
//	std::cout << std::bitset<sizeof(int) * 8>(b.getRawBits()) << std::endl;
//	return (0);
//}

//int		main(void)
//{
//	Fixed	const a(-34.73f);
//
//	std::cout << a << std::endl;
//	return (0);
//}

//int		main(void)
//{
//	Fixed	const a(54.5f);
//	Fixed	const b(7.25f);
//
//	std::cout << a << std::endl;
//	std::cout << b << std::endl;
//	std::cout << (a < b) << std::endl;
//	std::cout << (a > b) << std::endl;
//	std::cout << (a <= b) << std::endl;
//	std::cout << (a >= b) << std::endl;
//	std::cout << (a == b) << std::endl;
//	std::cout << (a == a) << std::endl;
//	std::cout << (a != b) << std::endl;
//	std::cout << (a != a) << std::endl;
//	return (0);
//}

int		main(void)
{
	Fixed	c(1020.25f);

	std::cout << c << std::endl;
	std::cout << c.toInt() << std::endl;
	std::cout << c.toFloat() << std::endl;
}


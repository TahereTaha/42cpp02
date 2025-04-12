/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:24:52 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/12 05:12:07 by tatahere         ###   ########.fr       */
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
//
//	std::cout << std::bitset<sizeof(int) * 8>(a.getRawBits()) << std::endl;
//	std::cout << a.toFloat() << std::endl;
//	std::cout << a.toInt() << std::endl;
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

int		main(void)
{
	Fixed	const a(-34.73f);

	std::cout << a << std::endl;
	return (0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:24:52 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/09 08:28:55 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "\n\ttesting with the default value.\n" << std::endl;
	{
		Fixed	a;
		Fixed	b(a);
		Fixed	c;
	
		c = b;
	
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	std::cout << "\n\ttesting with a 5.\n" << std::endl;
	{
		Fixed	a;
		a.setRawBits(5);
		Fixed	b(a);
		Fixed	c;
	
		c = b;
	
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	std::cout << "\n\ttesting with a -42.\n" << std::endl;
	{
		Fixed	a;
		a.setRawBits(-42);
		Fixed	b(a);
		Fixed	c;
	
		c = b;
	
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	return (0);
}

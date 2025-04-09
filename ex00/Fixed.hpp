/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:31:19 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/09 08:23:28 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed & src);	//	this is for not having to use more memory than needed.
		~Fixed(void);
		Fixed & operator=(const Fixed & src);

		int		getRawBits(void) const ;
		void	setRawBits(int const raw);
};

#endif

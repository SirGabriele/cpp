/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:38:49 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/06 15:07:39 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &src);
		Fixed(int const toConvert);
		Fixed(float const toConvert);
		~Fixed(void);
		Fixed &operator=(const Fixed &src);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		int 	toInt(void) const;
		float	toFloat(void) const;

	private:
		static int const	_binaryPoint = 8;
		int					_value;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &src);

#endif /*FIXED_HPP*/

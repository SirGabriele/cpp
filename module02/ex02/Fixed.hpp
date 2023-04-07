/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:38:49 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/06 19:13:37 by kbrousse         ###   ########.fr       */
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

		bool	operator>(const Fixed &toCompare) const;
		bool	operator<(const Fixed &toCompare) const;
		bool	operator<=(const Fixed &toCompare) const;
		bool	operator>=(const Fixed &toCompare) const;
		bool	operator==(const Fixed &toCompare) const;
		bool	operator!=(const Fixed &toCompare) const;
		
		Fixed	operator+(const Fixed &toAdd);
		Fixed	operator-(const Fixed &toSubstract);
		Fixed	operator*(const Fixed &toMultiply);
		Fixed	operator/(const Fixed &toDivide);

		Fixed	operator++(void);	/*prefix incrementation*/
		Fixed	operator++(int);	/*postfix incrementation*/
		Fixed	operator--(void);	/*prefix decrementation*/
		Fixed	operator--(int);	/*postfix decrementation*/

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		int 	toInt(void) const;
		float	toFloat(void) const;

		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);


	private:
		static int const	_binaryPoint = 8;
		int					_value;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &src);


#endif /*FIXED_HPP*/

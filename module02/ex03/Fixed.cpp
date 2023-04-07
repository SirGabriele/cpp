/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:18:23 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/06 19:15:35 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Fixed::Fixed(void): _value(0)
{

}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::Fixed(int const toConvert): _value(toConvert << _binaryPoint)
{

}

Fixed::Fixed(float const toConvert): _value(roundf(toConvert * (1 << _binaryPoint)))
{

}

Fixed::~Fixed(void)
{

}

Fixed &Fixed::operator=(const Fixed &src)
{
	this->_value = src.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	(void)raw;
}

int	Fixed::toInt(void) const
{
	return (this->_value >> this->_binaryPoint);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << this->_binaryPoint));
}

std::ostream	&operator<<(std::ostream &out, const Fixed &src)
{
	out << src.toFloat();
	return (out);
}

/*	START OF COMPARISON OPERATORS	*/
bool	Fixed::operator>(const Fixed &toCompare) const
{
	if (this->toFloat() > toCompare.toFloat())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<(const Fixed &toCompare) const
{
	if (this->toFloat() < toCompare.toFloat())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(const Fixed &toCompare) const
{
	if (this->toFloat() <= toCompare.toFloat())
		return (true);
	else
		return (false);
}

bool	Fixed::operator>=(const Fixed &toCompare) const
{
	if (this->toFloat() >= toCompare.toFloat())
		return (true);
	else
		return (false);
}

bool	Fixed::operator==(const Fixed &toCompare) const
{
	if (this->toFloat() == toCompare.toFloat())
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(const Fixed &toCompare) const
{
	if (this->toFloat() != toCompare.toFloat())
		return (true);
	else
		return (false);
}
/*	END OF COMPARISON OPERATORS*/

/*	START OF ARITHMETIC OPERATORS*/
Fixed	Fixed::operator+(const Fixed &toAdd)
{
	Fixed	res(this->toFloat() + toAdd.toFloat());

	return (res);
}

Fixed	Fixed::operator-(const Fixed &toSubstract)
{
	Fixed	res(this->toFloat() - toSubstract.toFloat());

	return (res);
}

Fixed	Fixed::operator*(const Fixed &toMultiply)
{
	Fixed	res(this->toFloat() * toMultiply.toFloat());

	return (res);
}

Fixed	Fixed::operator/(const Fixed &toDivide)
{
	Fixed	res(this->toFloat() / toDivide.toFloat());

	return (res);
}
/*	END OF ARITHMETIC OPERATORS*/

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return(a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

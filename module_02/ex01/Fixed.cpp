/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:18:23 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/06 15:30:37 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const toConvert): _value(toConvert << _binaryPoint)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const toConvert): _value(roundf(toConvert * (1 << _binaryPoint)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	if (this != &src)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		this->_value = src.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:34:42 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/08 15:29:22 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _x(0), _y(0)
{

}

Point::Point(const float xPos, const float yPos): _x(xPos), _y(yPos)
{

}

Point::Point(const Point &src): _x(src.getX()), _y(src.getY())
{

}

Point::~Point(void)
{

}

Point	&Point::operator=(const Point &src)
{
	std::cerr << "Point class has const private attributes. Thus you can not assign a Point instance to another" << std::endl;
	(void)src;
	return (*this);
}

bool	Point::operator==(const Point &toCompare)
{
	if (this->getX().getRawBits() == toCompare.getX().getRawBits()
		&& this->getY().getRawBits() == toCompare.getY().getRawBits())
		return (true);
	else
		return (false);
}

const Fixed	&Point::getX(void) const
{
	return (this->_x);
}

const Fixed	&Point::getY(void) const
{
	return (this->_y);
}

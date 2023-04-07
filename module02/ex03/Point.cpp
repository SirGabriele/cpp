/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:34:42 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/07 14:53:42 by kbrousse         ###   ########.fr       */
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
	std::cerr << "Point class has const private attributes. Thus you can not assign one Point to another" << std::endl;
	(void)src;
	return (*this);
}

const Fixed	&Point::getX(void) const
{
	return (this->_x);
}

const Fixed	&Point::getY(void) const
{
	return (this->_y);
}

/*Fixed	Point::getArea(const Fixed &baseLengthA, const Fixed &baseLengthB, const Fixed &baseLengthC) const
{
	Fixed	res;
	Fixed	baseLength;
	Fixed	altitude;

	(void)baseLengthA;
	(void)baseLengthB;
	(void)baseLengthC;
	return (res);
}

Fixed	Point::getLength(const Point &a, const Point &b) const
{
	Fixed	aX = a.getX();
	Fixed	bX = b.getX();
	Fixed	aY = a.getY();
	Fixed	bY = b.getY();
	float	length;

	length = sqrt(pow((bX - aX).toFloat(), 2) + pow((bY - aY).toFloat(), 2));
	return (Fixed(length));
}*/

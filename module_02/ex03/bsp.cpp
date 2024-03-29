/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:46:42 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/06 19:47:09 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	getArea(const Fixed &baseLengthA, const Fixed &baseLengthB,
	const Fixed &baseLengthC)
{
	float	a = baseLengthA.toFloat();
	float	b = baseLengthB.toFloat();
	float	c = baseLengthC.toFloat();
	float	area = 0.25 * sqrt((a + b + c) * (-a + b + c) * (a - b + c) * (a + b - c));

	if (area < 0 || area != area)
		area = 0;
	return (Fixed(area));
}

static	Fixed	getLength(const Point &a, const Point &b)
{
	Fixed	aX = a.getX();
	Fixed	bX = b.getX();
	Fixed	aY = a.getY();
	Fixed	bY = b.getY();
	float	length = sqrt(pow((bX - aX).toFloat(), 2) + pow((bY - aY).toFloat(), 2));

	if (length < 0 || length != length)
		length = 0;
	return (Fixed(length));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point	pointNonConst(point);

	if (pointNonConst == a || pointNonConst == b || pointNonConst == c)
	{
		std::cout << "point is on one of the triangle's vertices" << std::endl;
		return (false);
	}

	Fixed	ABLength(getLength(a, b));
	Fixed	BCLength(getLength(b, c));
	Fixed	ACLength(getLength(a, c));
	Fixed	APLength(getLength(a, point));
	Fixed	BPLength(getLength(b, point));
	Fixed	CPLength(getLength(c, point));

	Fixed	ABCArea(getArea(ABLength, BCLength, ACLength));
	Fixed	ABPArea(getArea(ABLength, BPLength, APLength));
	Fixed	BCPArea(getArea(BCLength, CPLength, BPLength));
	Fixed	APCArea(getArea(APLength, ACLength, CPLength));

	if (ABPArea == 0 || BCPArea == 0 || APCArea == 0)
	{
		std::cout << "point is on one of the triangle's edges" << std::endl;
		return (false);
	}

	Fixed	sumSubTriangles = ABPArea + BCPArea + APCArea;

	std::cout << "ABP Area = " << ABPArea << '\n';
	std::cout << "BCP Area = " << BCPArea << '\n';
	std::cout << "APC Area = " << APCArea << '\n';
	std::cout << "Sum of 3 subtriangles = " << sumSubTriangles << '\n';
	std::cout << "ABC Area = " << ABCArea << '\n';
	
	if (sumSubTriangles - ABCArea <= Fixed(0.1f))
		return (true);
	return (false);
}

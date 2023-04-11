/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:30:05 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/08 15:27:38 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POINT_HPP
# define POINT_HPP

# include <iostream> 
# include "Fixed.hpp"

class	Point
{
	public:
		Point(void);
		Point(const Point &src);
		Point(const float xPos, const float yPos);
		~Point(void);
		Point	&operator=(const Point &src);

		bool	operator==(const Point &toCompare);

		const Fixed	&getX(void) const;

		const Fixed	&getY(void) const;

	private:
		const Fixed	_x;
		const Fixed	_y;
};

#endif /*POINT_HPP*/

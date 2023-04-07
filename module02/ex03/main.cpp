/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:23:22 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/06 19:15:56 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main (void)
{
	const Point	a(0, 2);
	const Point	b(4, 0);
	const Point	c(6, 4);
	const Point	point(0.03, 2.0);
	Fixed(0.03f);

	if (bsp(a, b, c, point) == true)
		std::cout << "✅ The point is inside the triangle ✅" << std::endl;
	else
		std::cout << "❌ The point is not inside the triangle ❌" << std::endl;
	return (0);
}

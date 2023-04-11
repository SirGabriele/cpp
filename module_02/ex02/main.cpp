/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:23:22 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/08 13:45:37 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main (void)
{
	Fixed	a;
	Fixed	const b(Fixed(5.05f) * Fixed(2));
	Fixed	c(7.001f);
	Fixed	d(7.002f);
	Fixed	e(2);
	Fixed	f(10);
	Fixed	res;

/*	START OF COMPARISON OPERATORS TESTS	*/
/*	<	*/
	std::cout << c << " < " << d << '\n';
	if (c < d)
		std::cout << "✅" << '\n';
	else
		std::cout << "❌" << '\n';

/*	>	*/
	std::cout << c << " > " << d << '\n';
	if (c > d)
		std::cout << "✅" << '\n';
	else
		std::cout << "❌" << '\n';

/*	<=	*/
	std::cout << c << " <= " << d << '\n';
	if (c <= d)
		std::cout << "✅" << '\n';
	else
		std::cout << "❌" << '\n';

/*	>=	*/
	std::cout << c << " >= " << d << '\n';
	if (c >= d)
		std::cout << "✅" << '\n';
	else
		std::cout << "❌" << '\n';

/*	==	*/
	std::cout << c << " == " << d << '\n';
	if (c == d)
		std::cout << "✅" << '\n';
	else
		std::cout << "❌" << '\n';

/*	!=	*/
	std::cout << c << " != " << d << '\n';
	if (c != d)
		std::cout << "✅" << '\n';
	else
		std::cout << "❌" << '\n';
/*	END OF COMPARISON OPERATORS TESTS	*/

	std::cout << '\n';

/*	START OF ARITHMETIC OPERATORS TESTS	*/
/*	+	*/
	{
		std::cout << "Calculating " << e << " + " << f << '\n';
		res = e + f;
		std::cout << "Result = " << res << '\n';
	}

/*	-	*/
	{
		std::cout << "Calculating " << e << " - " << f << '\n';
		res = e - f;
		std::cout << "Result = " << res << '\n';
	}

/*	*	*/
	{
		std::cout << "Calculating " << e << " * " << f << '\n';
		res = e * f;
		std::cout << "Result = " << res << '\n';
	}

/*	/	*/
	{
		std::cout << "Calculating " << e << " / " << f << '\n';
		res = e / f;
		std::cout << "Result = " << res << '\n';
	}
/*	END OF ARITHMETIC OPERATORS TESTS	*/

	std::cout << '\n';

/*	START OF [PRE/POST][IN/DE]CREMENTATIONS	TESTS	*/
	std::cout << "Prefix incrementation" << '\n';
	std::cout << "a = " << a << '\n';
	std::cout << "++a = " << ++a << '\n';
	std::cout << "a = " << a << '\n';

	std::cout << "\nPostfix incrementation" << '\n';
	std::cout << "a = " << a << '\n';
	std::cout << "a++ = " << a++ << '\n';
	std::cout << "a = " << a << '\n';

	std::cout << "\nPrefix decrementation" << '\n';
	std::cout << "a = " << a << '\n';
	std::cout << "--a = " << --a << '\n';
	std::cout << "a = " << a << '\n';

	std::cout << "\nPostfix decrementation" << '\n';
	std::cout << "a = " << a << '\n';
	std::cout << "a-- = " << a-- << '\n';
	std::cout << "a = " << a << '\n';
/*	END OF [PRE/POST][IN/DE]CREMENTATIONS	TESTS	*/

	std::cout << '\n';
	std::cout << "b = " << b << '\n';
	std::cout << '\n';

	std::cout << "Between " << a << " and " << b << " ... "
			<< Fixed::max(a, b) << " is the largest" << '\n';
	std::cout << "Between " << a << " and " << b << " ... "
			<< Fixed::min(a, b) << " is the smallest" << std::endl;
	return 0;
}

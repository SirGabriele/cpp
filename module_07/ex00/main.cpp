/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:08:04 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/05 12:16:50 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int	main(void)
{
	int	a = 2;
	int	b = 3;
	int	c = 3;
	std::string d = "chaine1";
	std::string e = "chaine2";

	std::cout << "a = " << a << ", b = " << b << "\n...swapping values..." << '\n';
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << "\n\n";

	std::cout << "min(a, b) = " << ::min(a, b) << '\n';
	std::cout << "min(b, a) = " << ::min(b, a) << '\n';
	std::cout << "max(a, b) = " << ::max(a, b) << '\n';
	std::cout << "max(b, a) = " << ::max(b, a) << "\n\n";

	std::cout << "d = " << d << ", e = " << e << "\n...swapping values...\n";
	::swap(d, e);
	std::cout << "d = " << d << ", e = " << e << "\n\n";

	std::cout << "min(d, e) = " << ::min(d, e) << '\n';
	std::cout << "min(e, d) = " << ::min(e, d) << '\n';
	std::cout << "max(d, e) = " << ::max(d, e) << '\n';
	std::cout << "max(e, d) = " << ::max(e, d) << "\n\n";

	std::cout << "a = "<< a << ", c = " << c << "\nThe second value, c, should be returned\n";
	::min(a, c)++;
	std::cout << "::min(a, c)++;\n" << "a = " << a << "\nc = " << c << "\n\n";
	c--;
	std::cout << "c = "<< c << ", a = " << a << "\nThe second value, a, should be returned\n";
	::min(c, a)++;
	std::cout << "::min(c, a)++;\n" << "c = " << c << "\na = " << a << '\n';
	
	return 0;
}

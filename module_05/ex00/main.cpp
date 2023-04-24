/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:12:22 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/24 08:37:48 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	A;
		Bureaucrat	B("Bébère");
		Bureaucrat	C(149);
		Bureaucrat	D("Yannis", 2);
	
		std::cout << "A:\n" << A << '\n'
				<< "B:\n" << B << '\n'
				<< "C:\n" << C << '\n'
				<< "D:\n" << D
				<< '\n';
		D.promote();
		std::cout << D << std::endl;
		C.demote();
		std::cout << C << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	return (0);
}

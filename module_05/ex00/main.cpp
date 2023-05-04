/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:12:22 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/02 15:43:52 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void	line(void)
{
	std::cout << "--------------------------------------------------------" << std::endl;
}

int	main(void)
{
	try
	{
		Bureaucrat	A;
		Bureaucrat	B("Gilbert", 12);
		std::cout << "A:\n" << A << '\n';
		std::cout << "B:\n" << B << '\n';
		B = A;
		std::cout << "B:\n" << B << '\n';
		Bureaucrat	C(B);
		std::cout << "C:\n" << C << '\n';
	}
	catch (std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
		line();

	try
	{
		Bureaucrat	A("Yannis", 53);
		std::cout << "A:\n" << A << '\n';
	}
	catch (std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}

		line();
	
	try
	{
		Bureaucrat	A("Roger", 151);
		std::cout << "A:\n" << A << '\n';
	}
	catch (std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}

		line();
	
	try
	{
		Bureaucrat	A("Cliford", -1);
		std::cout << "A:\n" << A << '\n';
	}
	catch (std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}

		line();

	try
	{
		Bureaucrat	A("Baptiste", 0);
		std::cout << "A:\n" << A << '\n';
	}
	catch (std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	return (0);
}

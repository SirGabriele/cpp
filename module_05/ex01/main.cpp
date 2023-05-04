/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:12:22 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/24 08:48:28 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

		line();
		line();
		
	try
	{
		Form	A;
		Form	B("Shopping list", true, 5, 87);
		std::cout << "A:\n" << A << '\n';
		std::cout << "B:\n" << B << '\n';
		A = B;
		std::cout << "A:\n" << A << '\n';
		Form	C(B);
		std::cout << "C:\n" << C << '\n';
	}
	catch (std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}

		line();

	try
	{
		Form	A("Shopping list", true, -1, 53);
		std::cout << "A:\n" << A << '\n';
	}
	catch (std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}

		line();

	try
	{
		Form	A("Shopping list", true, 0, 53);
		std::cout << "A:\n" << A << '\n';
	}
	catch (std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}

		line();

	try
	{
		Form	A("Shopping list", true, 1, -1);
		std::cout << "A:\n" << A << '\n';
	}
	catch (std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}

		line();

	try
	{
		Form	A("Shopping list", true, 1, 0);
		std::cout << "A:\n" << A << '\n';
	}
	catch (std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}

		line();

	try
	{
		Form	A;
		std::cout << "A:\n" << A << '\n';
	}
	catch (std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}

		line();

	try
	{
		Form		A("Shopping list", false, 150, 150);
		Bureaucrat	B("Michel", 150);
		std::cout << "A:\n" << A << '\n'
				<< "B:\n" << B << '\n';
		std::cout << "..........Signing A.........." << '\n';
		B.signForm(A);
		std::cout << "A:\n" << A << '\n';

	}
	catch (std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}

		line();

	try
	{
		Form		A("Shopping list", true, 150, 150);
		Bureaucrat	B("Michel", 1);
		std::cout << "A:\n" << A << '\n'
				<< "B:\n" << B << '\n';
		std::cout << "..........Signing A.........." << '\n';
		B.signForm(A);
		std::cout << "A:\n" << A << '\n';

	}
	catch (std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}

		line();

	try
	{
		Form		A("Shopping list", false, 1, 1);
		Bureaucrat	B("Michel", 150);
		std::cout << "A:\n" << A << '\n'
				<< "B:\n" << B << '\n';
		std::cout << "..........Signing A.........." << '\n';
		B.signForm(A);
		std::cout << "A:\n" << A << '\n';

	}
	catch (std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	return (0);
}

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
	std::cout << "\n--------------------------------------------------------\n" << std::endl;
}

int	main(void)
{
	try
	{
		Bureaucrat	A("Bébère", 50);
		Bureaucrat	B;
		Form		C;
		Form		D("Death notice", false, 76, 6);

		std::cout << "Bureaucrat A:\n" << A << '\n'
				<< "Bureaucrat B:\n" << B << '\n'
				<< "Form C:\n" << C << '\n'
				<< "Form D:\n" << D << '\n';

			line();

		A.signForm(D);
		std::cout << "Form D:\n" << D << '\n';

			line();

		
		A.signForm(D);
		std::cout << "Form D:\n" << D << '\n';
	}
	catch (std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
			line();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:42:06 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/24 14:17:37 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::srand(std::time(NULL));

	Bureaucrat	jerome("Jérome", 1);
	Intern		flunky;
	AForm		*form = NULL;

	try
	{
		form = flunky.makeForm("shrubbery creation", "shruTarget");
		std::cout << *form << std::endl;
		try
		{
			jerome.signForm(*form);
			jerome.executeForm(*form);
			std::cout << *form << '\n' << std::endl;
		}
		catch (std::exception &exception)
		{
			std::cerr << exception.what() << std::endl;
		}
		delete form;
		form = flunky.makeForm("robotomy request", "robotTarget");
		std::cout << *form << std::endl;
		try
		{
			jerome.signForm(*form);
			jerome.executeForm(*form);
			std::cout << *form << '\n' << std::endl;
		}
		catch (std::exception &exception)
		{
			std::cerr << exception.what() << std::endl;
		}
		delete form;
		form = flunky.makeForm("presidential pardon", "presTarget");
		std::cout << *form << std::endl;
		try
		{
			jerome.signForm(*form);
			jerome.executeForm(*form);
			std::cout << *form << '\n' << std::endl;
		}
		catch (std::exception &exception)
		{
			std::cerr << exception.what() << std::endl;
		}
		delete form;
	}
	catch (std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	return (0);
}

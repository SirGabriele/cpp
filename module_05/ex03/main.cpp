/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:42:06 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/18 18:26:20 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void	pres(void)
{
//	return;
	AForm	*A = new PresidentialPardonForm("Pierre");

	try
	{
		Bureaucrat	signOnTheDot("signOnTheDot", 25);
		Bureaucrat	executeOnTheDot("executeOnTheDot", 5);

		std::cout << *A << std::endl;
		signOnTheDot.executeForm(*A);		/*	Executing a non signed form	*/
		signOnTheDot.signForm(*A);			/*	Signing form	*/
		executeOnTheDot.executeForm(*A);	/*	Executing a signed form	*/
		std::cout << *A << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	delete A;
}

static void	robot(void)
{
	return;
	AForm	*A = new RobotomyRequestForm("Colette");

	try
	{
		Bureaucrat	signOnTheDot("signOnTheDot", 72);
		Bureaucrat	executeOnTheDot("executeOnTheDot", 45);

		std::cout << *A << std::endl;
		signOnTheDot.executeForm(*A);		/*	Executing a non signed form	*/
		signOnTheDot.signForm(*A);			/*	Signing form	*/
		executeOnTheDot.executeForm(*A);	/*	Executing a signed form	*/
		std::cout << *A << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	delete A;
}

static void	shru(void)
{
	return;
	AForm	*A = new ShrubberyCreationForm("file");

	try
	{
		Bureaucrat	signOnTheDot("signOnTheDot", 145);
		Bureaucrat	executeOnTheDot("executeOnTheDot", 137);

		std::cout << *A << std::endl;
		signOnTheDot.executeForm(*A);		/*	Executing a non signed form	*/
		signOnTheDot.signForm(*A);			/*	Signing form	*/
		executeOnTheDot.executeForm(*A);	/*	Executing a signed form	*/
		std::cout << *A << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	delete A;
}

int	main(void)
{
	shru();
	robot();
	pres();
	return (0);
}

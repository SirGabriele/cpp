/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:42:06 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/04 14:46:47 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void	line(void)
{
	std::cout << "--------------------------------------------------------------" << std::endl;
}

static void	pres(void)
{
//	return;
	AForm	*A = new PresidentialPardonForm("Pierre");

	try
	{
		Bureaucrat	signOnTheDot("signOnTheDot", 25);
		Bureaucrat	executeOnTheDot("executeOnTheDot", 5);
		Bureaucrat	noob("noob", 150);

		std::cout << *A << std::endl;
		signOnTheDot.executeForm(*A);		/*	Executing a non signed form	*/
		signOnTheDot.signForm(*A);			/*	Signing form	*/
//		noob.executeForm(*A);				/*	Noob can't execute	*/
//		A->execute(noob);					/*	Noob can't execute	*/
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
//	return;
	AForm	*A = new RobotomyRequestForm("Colette");

	try
	{
		Bureaucrat	signOnTheDot("signOnTheDot", 72);
		Bureaucrat	executeOnTheDot("executeOnTheDot", 45);
		Bureaucrat	noob("noob", 150);

		std::cout << *A << std::endl;
		signOnTheDot.executeForm(*A);		/*	Executing a non signed form	*/
		signOnTheDot.signForm(*A);			/*	Signing form	*/
//		noob.executeForm(*A);				/*	Noob can't execute	*/
//		A->execute(noob);					/*	Noob can't execute	*/
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
//	return;
	AForm	*A = new ShrubberyCreationForm("AmazonRainforest");

	try
	{
		Bureaucrat	signOnTheDot("signOnTheDot", 145);
		Bureaucrat	executeOnTheDot("executeOnTheDot", 137);
		Bureaucrat	noob("noob", 150);


		std::cout << *A << '\n';;
		signOnTheDot.executeForm(*A);		/*	Executing a non signed form	*/
		signOnTheDot.signForm(*A);			/*	Signing form	*/
//		noob.executeForm(*A);				/*	Noob can't execute	*/
//		A->execute(noob);					/*	Noob can't execute	*/
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
	std::srand(std::time(NULL));

	shru();
		line();
	robot();
		line();
	pres();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:23:57 by kbrousse          #+#    #+#             */

/*   Updated: 2023/05/02 15:10:07 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

void	identify(Base &p)
{
	std::cout << "casted in type ";
	try
	{
		A	&a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &exception)
	{
	}
	try
	{
		B	&b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &exception)
	{
	}
	try
	{
		C	&c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::exception &exception)
	{
	}
}

void	identify(Base *p)
{
	A	*a = dynamic_cast<A *>(p);
	std::cout << "casted in type ";
	if (a != NULL)
		std::cout << " A" << std::endl;
	
	B	*b = dynamic_cast<B *>(p);
	if (b != NULL)
		std::cout << " B" << std::endl;

	C	*c = dynamic_cast<C *>(p);
	if (c != NULL)
		std::cout << " C" << std::endl;
}

Base	*generate(void)
{
	int	randomValue = std::rand() % 3;

	switch(randomValue)
	{
		case 0:
		{
			std::cout << "created A" << std::endl;
			return (new A());
		}
		case 1:
		{
			std::cout << "created B" << std::endl;
			return (new B());
		}
		case 2:
		{
			std::cout << "created C" << std::endl;
			return (new C());
		}
		default :
			return (NULL);
	}
}

int	main(void)
{
	std::srand(std::time(NULL));
	Base *p = NULL;

	std::cout << "Testing pointer function\n";
	for (int i = 0; i < 100; i++)
	{
		p = generate();
		identify(p);
		std::cout << "------------------------------------------------" << std::endl;
		delete p;
	}
	std::cout << "Testing reference function\n";
	for (int i = 0; i < 100; i++)
	{
		p = generate();
		identify(*p);
		std::cout << "------------------------------------------------" << std::endl;
		delete p;
	}
	return (0);
}

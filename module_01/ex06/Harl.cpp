/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:48:21 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/13 18:06:50 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	Harl::complain(std::string level)
{
	std::string	funcStr[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i;

	i = 0;
	for (; i < NB_FUNC; i++)
	{
		if (funcStr[i] == level)
			break ;
	}
	switch (i)
	{
		case 0:
		{
			this->debug();
			break ;
		}
		case 1:
		{
			this->info();
			break ;
		}
		case 2:
		{
			this->warning();
			break ;
		}
		case 3:
		{
			this->error();
			break ;
		}
		default:
		{
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
		}
	}
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\nThis is a debugging message\n" << std::endl;
	this->info();
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]\nThis is an info message\n" << std::endl;
	this->warning();
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]\nThis is a warning message\n" << std::endl;
	this->error();
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]\nThis is an error message\n" << std::endl;
}

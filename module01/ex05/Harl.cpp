/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:48:21 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/13 17:40:35 by kbrousse         ###   ########.fr       */
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
	std::string	funcStr[] = {"debug", "info", "warning", "error"};
	void		(Harl::*funcPtr[NB_FUNC])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int			i;

	i = 0;
	for (; i < NB_FUNC; i++)
	{
		if (funcStr[i] == level)
		{
			(this->*funcPtr[i])();
			return ;
		}
	}
	std::cout << "Invalid command" << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "This is a debugging message" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "This is an info message" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "This is a warning message" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is an error message" << std::endl;
}

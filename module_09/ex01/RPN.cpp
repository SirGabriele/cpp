/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:27:10 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/30 18:57:15 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{

}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN::~RPN(void)
{

}

RPN	&RPN::operator=(const RPN &src)
{
	static_cast<void>(src);
	return (*this);
}

bool	RPN::isInputValid(const std::string &input)
{
	int	nb = 0;
	int	op = 0;

	if (input[0] < '0' || input[0] > '9'
		|| input[2] < '0' || input[2] > '9'
		|| input.length() % 2 == 0)
		return (false);
	for (std::string::size_type i = 0; i < input.length(); i++)
	{
		if (i % 2 == 0)
		{
			if (input[i] >= '0' && input[i] <= '9')
			{
				nb++;
				continue ;
			}
			else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
			{
				op++;
				continue ;
			}
		}
		else if (std::isspace(input[i]) != 0)
			continue ;
	}
	if (nb != op + 1)
		return (false);
	return (true);
}

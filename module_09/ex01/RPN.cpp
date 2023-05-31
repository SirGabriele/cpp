/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:27:10 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/31 16:15:32 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<int>	RPN::_myStack;
std::string		RPN::_operatorStr = "+-*/";
char			RPN::_operatorArr[4] = {'+', '-', '*', '/'};
void			(*RPN::funcPtr[4])(void) = {&RPN::_add, &RPN::_sub, &RPN::_mul, &RPN::_div};

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
			//if (input[i] >= '0' && input[i] <= '9')
			if (std::isdigit(input[i]) != 0)
			{
				nb++;
				continue ;
			}
			//else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
			else if (RPN::_operatorStr.find_first_of(input[i], 0) != std::string::npos)
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

bool	RPN::calculate(char *input)
{
	char	*token = std::strtok(input, WHITESPACES);
	char	c;

	while (token != NULL)
	{
		c = token[0];
		if (token[1] != '\0')
		{
			std::cerr << "token.length() != 1" << std::endl;
			return (false);
		}
		else if (RPN::_operatorStr.find_first_of(c) != std::string::npos) //operator found;
		{
			int funcIndex = RPN::getOperatorIndex(c);
			switch (funcIndex)
			{
				case ADD:
				{
					RPN::_add();
					break ;
				}
				case SUB:
				{
					RPN::_sub();
					break ;
				}
				case MUL:
				{
					RPN::_mul();
					break ;
				}
				case DIV:
				{
					RPN::_div();
					break ;
				}
				default :
				{
					return (false);
				}
			}
		}
		else if (std::isdigit(c) != 0) //digit found
		{
			int	value = static_cast<int>(c) - 48;
			RPN::_myStack.push(value);
		}
		token = std::strtok(NULL, WHITESPACES);
	}
	return (true);
}

void	RPN::displayResult(void)
{
	std::cout << RPN::_myStack.top() << std::endl;
}

void	RPN::_add(void)
{
	int	a = RPN::_myStack.top();
	RPN::_myStack.pop();
	int	b = RPN::_myStack.top();
	RPN::_myStack.pop();
	RPN::_myStack.push(b + a);
}

void	RPN::_sub(void)
{
	int	a = RPN::_myStack.top();
	RPN::_myStack.pop();
	int	b = RPN::_myStack.top();
	RPN::_myStack.pop();
	RPN::_myStack.push(b - a);
}

void	RPN::_mul(void)
{
	int	a = RPN::_myStack.top();
	RPN::_myStack.pop();
	int	b = RPN::_myStack.top();
	RPN::_myStack.pop();
	RPN::_myStack.push(b * a);
}

void	RPN::_div(void)
{
	int	a = RPN::_myStack.top();
	RPN::_myStack.pop();
	int	b = RPN::_myStack.top();
	RPN::_myStack.pop();
	RPN::_myStack.push(b / a);
}

int	RPN::getOperatorIndex(char c)
{
	if (RPN::_myStack.size() < 2)
	{
		std::cerr << "Can not do operation for stack only contains one element" << std::endl;
		return (-1);
	}
	for (int i = 0; i < 4; i++)
	{
		if (RPN::_operatorArr[i] == c)
			return (i);
	}
	std::cerr << "Unknown operator found" << std::endl;
	return (-1);
}

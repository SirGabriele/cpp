/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:58:57 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/31 16:15:57 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error\n:Correct usage is <./RPN> \"argument containing operands and operator\"" << std::endl;
		return (1);
	}

	std::string	input = argv[1];

	if (RPN::isInputValid(input) != true)
	{
		std::cerr << "Invalid format" << std::endl;
		return (1);
	}
	else if (RPN::calculate(argv[1]) != true)
	{
		std::cerr << "Something went wrong..." << std::endl;
		return (1);
	}
	RPN::displayResult();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:58:57 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/30 18:57:07 by kbrousse         ###   ########.fr       */
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

	if (RPN::isInputvalid(input) != true)
	{
		std::cerr << "Invalid format" << std::endl;
		return (1);
	}

// a voir avec un espace en derniere position

	/*char		*token = std::strtok(argv[1], WHITESPACES);
	while (token != NULL)
	{
		std::cout << token << '\n';
		token = std::strtok(NULL, WHITESPACES);
	}*/
//	try
//	{
//
//	}
//	catch (std::exception &exception)
//	{
//		std::cerr << exception.what() << std::endl;
//	}
	return (0);
}

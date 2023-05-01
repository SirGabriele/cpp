/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:53:02 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/28 15:05:38 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Correct usage is: ./converter <literal>" << std::endl;
		return (1);
	}
	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch (std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	return (0);
}

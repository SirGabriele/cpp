/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:05:12 by kbrousse          #+#    #+#             */
/*   Updated: 2023/06/13 13:22:52 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error:\nCorrect usage is <./btc> <input file>" << std::endl;
		return (1);
	}

	std::string	input = argv[1];

	try
	{
		BitcoinExchange::openFile("data.csv");
		BitcoinExchange::analyseDB();
		BitcoinExchange::closeFile("data.csv");
		BitcoinExchange::openFile(input);
		BitcoinExchange::analyseInput();
		BitcoinExchange::closeFile(input);
	}
	catch (std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
		return (1);
	}
	return (0);
}

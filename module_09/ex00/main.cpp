/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:05:12 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/30 15:36:45 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error:\nCorrect usage is <./btc> <input file>" << std::endl;
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
		std::cerr << exception.what() << std::endl;
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:05:12 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/18 15:59:28 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << "Error:\nCorrect usage is <./btc> <input file>" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange::openDBFile();
		BitcoinExchange::analyseDB();
		BitcoinExchange::closeDBFile();
	}
	catch (std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
		return (1);
	}
	return (0);
}

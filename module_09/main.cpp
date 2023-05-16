/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:05:12 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/16 18:27:58 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>
#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	std::ifstream	infile(argv[1]);

	if (argc != 2)
	{
		std::cerr << "Error:\nCorrect usage is <./btc> <input file>" << std::endl;
		return (1);
	}
	else if (infile.is_open() == false)
		std::cerr << "Error:\nCould not open <" << argv[1] << ">" << std::endl;
	
	std::string	line;
	for (; getline(infile, line);)
	{
		infile >> line;
		if (line.empty() == true)
			std::cerr << "Error:\nEmpty line found\n";
		else
			std::cout << line << std::endl;
	}
}

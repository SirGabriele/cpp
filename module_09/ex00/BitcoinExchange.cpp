/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:30:37 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/18 17:48:37 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::ifstream	BitcoinExchange::_infile;

BitcoinExchange::BitcoinExchange(void)
{

};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange(void)
{

}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &src)
{
	static_cast<void>(src);
	return (*this);
}

		/*	START OF EXCEPTIONS	*/
BitcoinExchange::InvalidDB::InvalidDB(const std::string &str) throw(): _errMsg("Invalid DataBase:\n" + str)
{
	
}

BitcoinExchange::InvalidDB::~InvalidDB(void) throw()
{

}

const char	*BitcoinExchange::InvalidDB::what(void) const throw()
{
	return (this->_errMsg.c_str());
}
		/*	END OF EXCEPTIONS	*/

void	BitcoinExchange::openDBFile(void)
{
	BitcoinExchange::_infile.open("data.csv");
	if (BitcoinExchange::_infile.is_open() == false)
		throw InvalidDB("Failed to open <data.csv>");
}

void	BitcoinExchange::closeDBFile(void)
{
	BitcoinExchange::_infile.close();
	if (BitcoinExchange::_infile.rdstate() == std::ios_base::failbit)
		throw InvalidDB("Failed to close <data.csv>");
}

void	BitcoinExchange::formatError(unsigned int i, const std::string &line)
{
	std::cerr << "Error: line " << i
			<< " does not respect the expected format <xxxx-xx-xx,<int, float>>. Found <"
			<< line << ">" << std::endl;
}

void	BitcoinExchange::analyseDB(void)
{
	std::string		line;
	unsigned int	i = 2;

	std::getline(BitcoinExchange::_infile, line);
	if (line != "date,exchange_rate")
		throw InvalidDB("Header is invalid. Expected <date,exchange_rate> but found <" + line + ">.");
	while (std::getline(BitcoinExchange::_infile, line))
	{
		if (line.empty() == true)
			std::cerr << "Error: line " << i << " is empty... Skipping it.\n";
		else if (analyseLine(line) != true)
			BitcoinExchange::formatError(i, line);
		else
		{
			//add to map
		}
		i++;
	}
}

bool	BitcoinExchange::analyseLine(const std::string &line)
{
	std::string::size_type	commaIndex = line.find_first_of(',', 0);

	if (commaIndex == std::string::npos || commaIndex != 10)
		return (false);
	if (analyseDate(line.substr(0, commaIndex)) != true)
		return (false);
	return (true);
}

bool	BitcoinExchange::analyseDate(const std::string &date)
{
//	int	j = 0;
	std::string::size_type	firstDashIndex = date.find_first_of('-', 0);
	std::string::size_type	secondDashIndex = date.find_first_of('-', firstDashIndex + 1);

	if (firstDashIndex == std::string::npos
		|| secondDashIndex == std::string::npos
		|| firstDashIndex != 4 || secondDashIndex != 7)
		return (false);

		//sait que les dash sont au bon endroit. reste à determiner si xxxx-xx-xx x ne sont bien que des digits

/*
	while (date[j] != '\0')
	{
		if (j == 4 || j == 7)
			;
		else if (date[j] < '0' || date[j] > '9')
			return (false);
		j++;
	}
	*/
	return (true);
}

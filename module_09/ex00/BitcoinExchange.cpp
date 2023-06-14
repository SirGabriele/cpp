/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:30:37 by kbrousse          #+#    #+#             */
/*   Updated: 2023/06/13 13:22:41 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::ifstream					BitcoinExchange::_infile;
std::map<std::string, float>	BitcoinExchange::_myMap;
std::string						BitcoinExchange::_date;
float							BitcoinExchange::_value;

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

void	BitcoinExchange::openFile(const std::string &name)
{
	BitcoinExchange::_infile.open(name.c_str());
	if (BitcoinExchange::_infile.is_open() == false)
		throw InvalidDB("Failed to open " + name);
}

void	BitcoinExchange::closeFile(const std::string &name)
{
	BitcoinExchange::_infile.close();
	if (BitcoinExchange::_infile.rdstate() == std::ios_base::failbit)
		throw InvalidDB("Failed to close " + name);
}

void	BitcoinExchange::DBFormatError(unsigned int i, const std::string &line)
{
	std::cout << "Error: data.csv | line " << i
			<< " does not respect the expected format <xxxx-xx-xx,<int, float>>. Found <"
			<< line << "> ... Skipping it." << std::endl;
}

void	BitcoinExchange::InputFormatError(unsigned int i, const std::string &line)
{
	std::cout << "Error: provided file | line " << i
			<< " does not respect the expected format <xxxx-xx-xx,<int, float>>. Found <"
			<< line << "> ... Skipping it." << std::endl;
}

bool	BitcoinExchange::analyseDB(void)
{
	std::string		line;
	unsigned int	i = 2;

	std::getline(BitcoinExchange::_infile, line);
	if (line != "date,exchange_rate")
		throw InvalidDB("Header is invalid. Expected <date,exchange_rate> but found <" + line + ">.");
	while (std::getline(BitcoinExchange::_infile, line))
	{
		if (line.empty() == true)
			std::cout << "Error: line " << i << " is empty... Skipping it.\n";
		else if (analyseLine(line, ",") != true)
			BitcoinExchange::DBFormatError(i, line);
		else if (BitcoinExchange::_value < 0)
		{
			std::cout << "Value for exchange rate must be positive" << std::endl;
			BitcoinExchange::InputFormatError(i, line);
		}
		else
		{
			try
			{
				std::pair<std::map<std::string, float>::iterator, bool> success =
					BitcoinExchange::_myMap.insert(std::pair<std::string, float>
					(BitcoinExchange::_date, BitcoinExchange::_value));
				if (success.second == false)
				{
					std::cout << "Insertion failed, key has already been declared previously"
							<< std::endl;
					return (false);
				}
			}
			catch (std::exception &exception)
			{
				std::cout << "Memory allocation failed" << std::endl;
				return (false);
			}
		}
		i++;
	}
	return (true);
}

void	BitcoinExchange::analyseInput(void)
{
	std::string		line;
	unsigned int	i = 2;

	std::getline(BitcoinExchange::_infile, line);
	if (line != "date | value")
		throw InvalidDB("Header is invalid. Expected <date | value> but found <" + line + ">.");
	while (std::getline(BitcoinExchange::_infile, line))
	{
		if (line.empty() == true)
			std::cout << "Error: line " << i << " is empty... Skipping it.\n";
		else if (analyseLine(line, " | ") != true)
			BitcoinExchange::InputFormatError(i, line);
		else if (BitcoinExchange::_value > 1000 || BitcoinExchange::_value < 0)
			BitcoinExchange::InputFormatError(i, line);
		else
		{
			std::map<std::string, float>::iterator it = BitcoinExchange::_myMap.upper_bound(BitcoinExchange::_date);
			//if (it->first != BitcoinExchange::_date && it != BitcoinExchange::_myMap.begin())
			if (it != BitcoinExchange::_myMap.begin() || it->first == BitcoinExchange::_date)
			{
				--it;
				double	product = BitcoinExchange::_value * it->second;

				std::cout << BitcoinExchange::_date << " => " << it->second << " = " << product << std::endl;
			}
			else
				std::cout << "Error: provided file | line " << i << "'s date is prior to database's first date" << std::endl;
		}
		i++;
	}
}

bool	BitcoinExchange::analyseLine(const std::string &line, const std::string &separator)
{
	std::string::size_type	separatorIndex = line.find(separator, 0);
	std::string::size_type	firstDashIndex = line.find_first_of('-', 0);
	std::string::size_type	secondDashIndex = line.find_first_of('-', firstDashIndex + 1);

	if (separatorIndex == std::string::npos || separatorIndex != 10
		|| firstDashIndex == std::string::npos
		|| secondDashIndex == std::string::npos
		|| firstDashIndex != 4 || secondDashIndex != 7)
		return (false);
	if (analyseDate(line.substr(0, separatorIndex)) != true)
		return (false);
	if (isDateValid(line.substr(0, separatorIndex), firstDashIndex, secondDashIndex) != true)
		return (false);
	if (analyseValue(line.substr(separatorIndex + separator.length(), line.length() - separatorIndex)) != true)
		return (false);
	return (true);
}

bool	BitcoinExchange::analyseDate(const std::string &date)
{
	for (std::string::size_type i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
			continue ;
		else if (std::isdigit(date[i]) == 0)
			return (false);
	}
	return (true);
}

bool	BitcoinExchange::isDateValid(const std::string &date, std::string::size_type firstDashIndex, std::string::size_type secondDashIndex)
{
	std::string	months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	std::string	yearStr = date.substr(0, firstDashIndex);
	std::string	monthStr = date.substr(firstDashIndex + 1, 2);
	std::string	dayStr = date.substr(secondDashIndex + 1, 2);

	int			daysInMonths[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int			yearInt = atoi(yearStr.c_str());
	int			monthInt = atoi(monthStr.c_str());
	int			dayInt = atoi(dayStr.c_str());

	bool		isLeapYear = ((yearInt % 4 == 0) && (yearInt % 100 != 0)) || (yearInt % 400 == 0);

	if (monthInt > 12 || dayInt > 31)//month or day exceeds max possible values
		return (false);
	else if (dayInt > daysInMonths[monthInt - 1])//day exceeds the months days
		return (false);
	else if (yearInt <= 2009 && monthInt <= 1 && dayInt < 3)//date is prior to Bitcoin creation
	{
		std::cout << "Bitcoin appeared on January 3rd 2009. So this date is invalid" << std::endl;
		return (false);
	}
	if ((isLeapYear == false && monthInt == 2 && dayInt > 28)
		|| (isLeapYear == true && monthInt == 2 && dayInt > 29))//Feb. 29th during a non leap year
		return (false);
	BitcoinExchange::_date = date;
	return (true);
}

bool	BitcoinExchange::analyseValue(const std::string &valueStr)
{
	bool	negSign = false;
	bool	dotFound = false;
	float	value = atof(valueStr.c_str());

	for (std::string::size_type i = 0; i < valueStr.length(); i++)
	{
		if (valueStr[i] == '.')
		{
			if (dotFound == true)
				return (false);
			dotFound = true;
		}
		else if (valueStr[i] == '-')
		{
			if (negSign == true)
				return (false);
			negSign = true;
		}
		else if (std::isdigit(valueStr[i]) == 0)
			return (false);
	}
	BitcoinExchange::_value = value;
	return (true);
}

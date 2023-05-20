/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:30:37 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/20 18:13:39 by kbrousse         ###   ########.fr       */
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
			<< line << ">... Skipping it." << std::endl;
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
	std::string::size_type	firstDashIndex = line.find_first_of('-', 0);
	std::string::size_type	secondDashIndex = line.find_first_of('-', firstDashIndex + 1);

	if (commaIndex == std::string::npos || commaIndex != 10
		|| firstDashIndex == std::string::npos
		|| secondDashIndex == std::string::npos
		|| firstDashIndex != 4 || secondDashIndex != 7)
		return (false);
	if (analyseDate(line.substr(0, commaIndex)) != true)
		return (false);
	if (isDateValid(line.substr(0, commaIndex), firstDashIndex, secondDashIndex) != true)
		return (false);
	if (analyseExchangeRate(line.substr(commaIndex + 1, line.length() - commaIndex)) != true)
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

	bool		isLeapYear = false;

	std::time_t	now = std::time(NULL);
	std::tm		*currentTime = std::localtime(&now);

	if (monthInt > 12 || dayInt > 31)//month or day is totally invalid
	{
		std::cout << "Max month is 12 and max day number is 31" << std::endl;
		return (false);
	}
	else if (dayInt > daysInMonths[monthInt - 1])//day exceeds the months days
	{
		std::cout << months[monthInt - 1] << " has " << daysInMonths[monthInt - 1] << " days at max" << std::endl;
		return (false);
	}
	else if (yearInt <= 2009 && monthInt <= 1 && dayInt < 3)//date is prior to Bitcoin creation
	{
		std::cerr << "Bitcoin appeared on January 3rd 2009. So this date is invalid" << std::endl;
		return (false);
	}
	else if (yearInt >= 1900 + currentTime->tm_year
		&& monthInt >= currentTime->tm_mon + 1
		&& dayInt > currentTime->tm_mday)//date is in the future
	{
		std::cerr << "This date is in the future" << std::endl;
		return (false);
	}
	if (((yearInt % 4 == 0) && (yearInt % 100 != 0)) || (yearInt % 400 == 0))
		isLeapYear = true;
	if ((isLeapYear == false && monthInt == 2 && dayInt > 28)
		|| (isLeapYear == true && monthInt == 2 && dayInt > 29))//Feb. 29th during a non leap year
	{
		std::cerr << "This year is not a leap year. Thus the day can not be " << dayInt << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::analyseExchangeRate(const std::string &exchangeRate)
{
	bool	dotFound = false;
	float	value = atof(exchangeRate.c_str());

	if (value > 1000)
	{
		std::cout << "Valid values for exchange rate are between 0 and 1000" << std::endl;
		return (false);
	}
	for (std::string::size_type i = 0; i < exchangeRate.length(); i++)
	{
		if (exchangeRate[i] == '.')
		{
			if (dotFound == true)
				return (false);
			dotFound = true;
		}
		else if (std::isdigit(exchangeRate[i]) == 0)
			return (false);
	}
	return (true);
}

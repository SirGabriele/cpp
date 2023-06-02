/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:22:25 by kbrousse          #+#    #+#             */
/*   Updated: 2023/06/02 18:54:48 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>	PmergeMe::_myVector;
std::list<int>		PmergeMe::_myList;

PmergeMe::PmergeMe(void)
{

}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe::~PmergeMe(void)
{

}

PmergeMe	&PmergeMe::operator=(const PmergeMe &src)
{
	static_cast<void>(src);
	return (*this);
}

bool	PmergeMe::isSequenceValid(const std::string &sequence)
{
	for (std::string::size_type i = 0; i < sequence.length(); i++)
	{
		if (std::isdigit(sequence[i]) == 0 && std::isspace(sequence[i]) == 0)
		{
			std::cout << B_HI_RED << "Error\n" << RESET << "Invalid element found in the sequence. Only accepts digits and spaces" << std::endl;
			return (false);
		}
	}
	return (true);
}

bool	PmergeMe::fillVector(char *sequence)
{
	long	value;
	int		i = std::strlen(sequence);
	char	*temp = new char[i + 1];

	temp = std::strcpy(temp, sequence);
	temp[i] = '\0';

	char	*token = std::strtok(temp, WHITESPACES);
	while (token != NULL)
	{
		value = std::strtol(token, NULL, 10);
		if (value == std::numeric_limits<long>::max() || value == std::numeric_limits<long>::min()
		|| value > std::numeric_limits<int>::max() || value == std::numeric_limits<int>::min())
		{
			std::cout << B_HI_RED << "Error\n" << RESET << "Found value superior to MAX_INT" << std::endl;
			return (false);
		}
		try
		{
			PmergeMe::_myVector.push_back(value);
		}
		catch (std::exception &exception)
		{
			std::cout << exception.what() << std::endl;
			return (false);
		}
		token = std::strtok(NULL, WHITESPACES);
	}
	delete [] temp;
	return (true);
}

bool	PmergeMe::fillList(char *sequence)
{
	long	value;
	int		i = std::strlen(sequence);
	char	*temp = new char[i + 1];

	temp = std::strcpy(temp, sequence);
	temp[i] = '\0';

	char	*token = std::strtok(temp, WHITESPACES);
	while (token != NULL)
	{
		value = std::strtol(token, NULL, 10);
		if (value == std::numeric_limits<long>::max() || value == std::numeric_limits<long>::min()
			|| value > std::numeric_limits<int>::max() || value == std::numeric_limits<int>::min())
		{
			std::cout << B_HI_RED << "Error\n" << RESET << "Found value superior to MAX_INT" << std::endl;
			return (false);
		}
		try
		{
			PmergeMe::_myList.push_back(value);
		}
		catch (std::exception &exception)
		{
			std::cout << exception.what() << std::endl;
			return (false);
		}
		token = std::strtok(NULL, WHITESPACES);
	}
	delete [] temp;
	return (true);
}

void	PmergeMe::displayVector(void)
{
	for (std::vector<int>::iterator it = PmergeMe::_myVector.begin(); it != PmergeMe::_myVector.end(); it++)
	{
		std::cout << *it;
		if (it != --PmergeMe::_myVector.end())
			std::cout << ' ';
	}
}

void	PmergeMe::displayList(void)
{
	for (std::list<int>::iterator it = PmergeMe::_myList.begin(); it != PmergeMe::_myList.end(); it++)
	{
		std::cout << *it;
		if (it != --PmergeMe::_myList.end())
			std::cout << ' ';
	}
}

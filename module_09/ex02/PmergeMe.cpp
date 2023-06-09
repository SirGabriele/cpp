/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:22:25 by kbrousse          #+#    #+#             */
/*   Updated: 2023/06/09 17:40:44 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<std::pair<int, int> >	PmergeMe::pairVector;
std::vector<int>					PmergeMe::myVector;
std::list<int>						PmergeMe::myList;
std::pair<bool, int>				PmergeMe::_oddValue(false, 0);

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
			PmergeMe::myVector.push_back(value);
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

void	PmergeMe::createPairsVector(std::vector<int> &vector)
{
	if (vector.size() % 2 == 1)
	{
		PmergeMe::_oddValue = std::make_pair(true, vector.back());
		vector.pop_back();
	}
	for (std::vector<int>::size_type i = 0; i < vector.size(); i += 2)
	{
		PmergeMe::pairVector.push_back(std::make_pair(vector[i], vector[i + 1]));
	}
}

std::vector<std::pair<int, int> >	PmergeMe::sortPairsVector(std::vector<std::pair<int, int> > &vector)
{
	if (vector.size() == 1)
	{
		if (vector.front().first > vector.front().second)
			std::swap(vector.front().first, vector.front().second);
		return (vector);
	}

	std::vector<std::pair<int, int> >	left;
	std::vector<std::pair<int, int> >	right;

	for (std::vector<int>::size_type i = 0; i < vector.size() / 2; i++)
	{
		left.push_back(std::make_pair(vector[i].first, vector[i].second));
	}
	for (std::vector<int>::size_type i = vector.size() / 2; i < vector.size(); i++)
	{
		right.push_back(std::make_pair(vector[i].first, vector[i].second));
	}
	left = PmergeMe::sortPairsVector(left);
	right = PmergeMe::sortPairsVector(right);
	return (PmergeMe::mergePairsVector(left, right));
}

std::vector<std::pair<int, int> >	PmergeMe::mergePairsVector(std::vector<std::pair<int, int> > &left, std::vector<std::pair<int, int> > &right)
{
	std::vector<std::pair<int, int> >	merged;

	for (std::vector<std::pair<int, int> >::size_type i = 0; i < left.size(); i++)
	{
		merged.push_back(left[i]);
	}
	for (std::vector<std::pair<int, int> >::size_type i = 0; i < right.size(); i++)
	{
		merged.push_back(right[i]);
	}
	return (merged);
}

void	PmergeMe::createMainSequenceVector(std::vector<std::pair<int, int> > &pairs)
{
	PmergeMe::myVector.clear();
	PmergeMe::myVector.push_back(pairs[0].second);
	for (std::vector<std::pair<int, int> >::size_type i = 1; i < pairs.size(); i++)
	{
		int	value = pairs[i].second;
		int j = i - 1;

		int							insertPos = binarySearchVector(PmergeMe::myVector, 0, j, value);
		std::vector<int>::iterator	it = PmergeMe::myVector.begin();

		for (int i = 0; i < insertPos; i++)
		{
			it++;
		}
		PmergeMe::myVector.insert(it, value);
	}
}

void	PmergeMe::insertPendingValuesVector(std::vector<std::pair<int, int> > &pairs)
{
	int							value;
	int							j;
	int							insertPos;
	std::vector<int>::iterator	it;

	for (std::vector<std::pair<int, int> >::size_type i = 0; i < pairs.size(); i++)
	{
		value = pairs[i].first;
		j = PmergeMe::myVector.size() - 1;

		insertPos = binarySearchVector(PmergeMe::myVector, 0, j, value);
		it = PmergeMe::myVector.begin();

		for (int i = 0; i < insertPos; i++)
		{
			it++;
		}
		PmergeMe::myVector.insert(it, value);
	}
	if (PmergeMe::_oddValue.first == true)
	{
		value = PmergeMe::_oddValue.second;
		j = PmergeMe::myVector.size() - 1;
		insertPos = binarySearchVector(PmergeMe::myVector, 0, j, value);
		it = PmergeMe::myVector.begin();
		for (int i = 0; i < insertPos; i++)
		{
			it++;
		}
		PmergeMe::myVector.insert(it, value);
	}
}

int	PmergeMe::binarySearchVector(std::vector<int> &vector, int lowerLimit, int upperLimit, int value)
{
	while (lowerLimit <= upperLimit)
	{
		int middle = lowerLimit + (upperLimit - lowerLimit) / 2;

		if (vector[middle] == value)
			return (middle);

		if (vector[middle] < value)
			lowerLimit = middle + 1;
		else
			upperLimit = middle - 1;
	}
	return (lowerLimit);
}

void	PmergeMe::displayVector(void)
{
	for (std::vector<int>::iterator it = PmergeMe::myVector.begin(); it != PmergeMe::myVector.end(); it++)
	{
		std::cout << *it;
		if (it != --PmergeMe::myVector.end())
			std::cout << ' ';
	}
}

/*
							----------LIST----------
*/

bool	PmergeMe::fillList(char *sequence)
{
	long	value;
	int		i = std::strlen(sequence);
	char	*temp = new char[i + 1];

	temp = std::strcpy(temp, sequence);

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
			PmergeMe::myList.push_back(value);
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

void	PmergeMe::displayList(void)
{
	for (std::list<int>::iterator it = PmergeMe::myList.begin(); it != PmergeMe::myList.end(); it++)
	{
		std::cout << *it;
		if (it != --PmergeMe::myList.end())
			std::cout << ' ';
	}
}

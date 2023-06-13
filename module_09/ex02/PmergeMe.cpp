/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:22:25 by kbrousse          #+#    #+#             */
/*   Updated: 2023/06/13 11:19:37 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<std::pair<int, int> >	PmergeMe::pairVector;
std::list<std::pair<int, int> >		PmergeMe::pairList;
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

	for (std::vector<std::pair<int, int> >::size_type i = 0; i < vector.size() / 2; i++)
	{
		left.push_back(std::make_pair(vector[i].first, vector[i].second));
	}
	for (std::vector<std::pair<int, int> >::size_type i = vector.size() / 2; i < vector.size(); i++)
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
		int							insertPos = binarySearchVector(PmergeMe::myVector, 0, PmergeMe::myVector.size() - 1, value);
		std::vector<int>::iterator	it = PmergeMe::myVector.begin();

		std::advance(it, insertPos);
		PmergeMe::myVector.insert(it, value);
	}
}

void	PmergeMe::insertPendingValuesVector(std::vector<std::pair<int, int> > &pairs)
{
	int							value;
	int							insertPos;
	std::vector<int>::iterator	it;

	for (std::vector<std::pair<int, int> >::size_type i = 0; i < pairs.size(); i++)
	{
		value = pairs[i].first;

		insertPos = binarySearchVector(PmergeMe::myVector, 0, PmergeMe::myVector.size() - 1, value);
		it = PmergeMe::myVector.begin();
		std::advance(it, insertPos);
		PmergeMe::myVector.insert(it, value);
	}
	if (PmergeMe::_oddValue.first == true)
	{
		value = PmergeMe::_oddValue.second;
		insertPos = binarySearchVector(PmergeMe::myVector, 0, PmergeMe::myVector.size() - 1, value);
		it = PmergeMe::myVector.begin();
		std::advance(it, insertPos);
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

void	PmergeMe::createPairsList(std::list<int> &list)
{
	if (list.size() % 2 == 1)
	{
		PmergeMe::_oddValue = std::make_pair(true, list.back());
		list.pop_back();
	}
	for (std::list<int>::iterator it = list.begin(); it != list.end(); std::advance(it, 2))
	{
		std::list<int>::iterator	next = it;
		std::advance(next, 1);
		PmergeMe::pairList.push_back(std::make_pair(*it, *next));
	}
}

std::list<std::pair<int, int> >	PmergeMe::sortPairsList(std::list<std::pair<int, int> > &list)
{
	if (list.size() == 1)
	{
		if (list.front().first > list.front().second)
			std::swap(list.front().first, list.front().second);
		return (list);
	}

	std::list<std::pair<int, int> >				left;
	std::list<std::pair<int, int> >				right;
	std::list<std::pair<int, int> >::iterator	middle = list.begin();
	std::advance(middle, list.size() / 2);

	for (std::list<std::pair<int, int> >::iterator it = list.begin(); it != middle; it++)
	{
		left.push_back(std::make_pair(it->first, it->second));
	}
	for (std::list<std::pair<int, int> >::iterator it = middle; it != list.end(); it++)
	{
		right.push_back(std::make_pair(it->first, it->second));
	}
	left = PmergeMe::sortPairsList(left);
	right = PmergeMe::sortPairsList(right);
	return (PmergeMe::mergePairsList(left, right));
}

std::list<std::pair<int, int> >	PmergeMe::mergePairsList(std::list<std::pair<int, int> > &left, std::list<std::pair<int, int> > &right)
{
	std::list<std::pair<int, int> >	merged;

	for (std::list<std::pair<int, int> >::iterator it = left.begin(); it != left.end(); it++)
	{
		merged.push_back(*it);
	}
	for (std::list<std::pair<int, int> >::iterator it = right.begin(); it != right.end(); it++)
	{
		merged.push_back(*it);
	}
	return (merged);
}

void	PmergeMe::createMainSequenceList(std::list<std::pair<int, int> > &pairs)
{
	PmergeMe::myList.clear();
	PmergeMe::myList.push_back(pairs.front().second);
	for (std::list<std::pair<int, int> >::iterator it = ++pairs.begin(); it != pairs.end(); it++)
	{
		int							value = it->second;
		int							insertPos = binarySearchList(PmergeMe::myList, 0, PmergeMe::myList.size() - 1, value);
		std::list<int>::iterator	pos = PmergeMe::myList.begin();

		std::advance(pos, insertPos);
		PmergeMe::myList.insert(pos, value);
	}
}

int	PmergeMe::binarySearchList(std::list<int> &list, int lowerLimit, int upperLimit, int value)
{
	while (lowerLimit <= upperLimit)
	{
		int middle = lowerLimit + (upperLimit - lowerLimit) / 2;

		std::list<int>::iterator	it = list.begin();
		std::advance(it, middle);
		if (*it == value)
			return (middle);

		if (*it < value)
			lowerLimit = middle + 1;
		else
			upperLimit = middle - 1;
	}
	return (lowerLimit);
}

void	PmergeMe::insertPendingValuesList(std::list<std::pair<int, int> > &pairs)
{
	int							value;
	int							insertPos;
	std::list<int>::iterator	it;
	std::list<int>::iterator	pos; 

	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		value = it->first;
		insertPos = binarySearchList(PmergeMe::myList, 0, PmergeMe::myList.size() - 1, value);
		pos = PmergeMe::myList.begin();
		std::advance(pos, insertPos);
		PmergeMe::myList.insert(pos, value);
	}
	if (PmergeMe::_oddValue.first == true)
	{
		value = PmergeMe::_oddValue.second;
		insertPos = binarySearchList(PmergeMe::myList, 0, PmergeMe::myList.size() - 1, value);
		pos = PmergeMe::myList.begin();
		std::advance(pos, insertPos);
		PmergeMe::myList.insert(pos, value);
	}
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

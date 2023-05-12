/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:28:31 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/12 18:00:40 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void): _length(0)
{

}

Span::Span(unsigned int n): _length(n)
{

}

Span::Span(const Span &src)
{
	*this = src;
}

Span::~Span(void)
{

}

Span	&Span::operator=(const Span &src)
{
	if (this != &src)
	{
		this->_length = src._length;
		this->_multiset = src._multiset;
	}
	return (*this);
}

unsigned int	Span::getLength(void) const
{
	return (this->_length);
}

void	Span::printMultiset(void) const
{
	std::multiset<int>::iterator second = this->_multiset.begin();
	std::multiset<int>::iterator first;
	int	currentSpan;
	int	i = 0;

	first = second++;
	std::cout << "this_multiset.size() = " << this->_multiset.size() << '\n';
	std::cout << i++ << ": " << *first;
	while (first != this->_multiset.end())
	{
		if (first != this->_multiset.begin())
		{
			std::cout << i++ << ": " << *first;
			std::cout << "\t<-- +" << currentSpan;
		}
		std::cout << '\n';
		if (second != this->_multiset.end())
			currentSpan = *second - *first;
		first = second++;
	}
}

void	Span::addNumber(int value)
{
	if (this->_multiset.size() >= this->_length)
		throw isFull();
	this->_multiset.insert(value);
}

void	Span::shortestSpan(void)
{
	if (this->_multiset.size() <= 1)
	{
		std::cerr << "Longest span calculation can not proceed for the the containers does not contain enough values" << std::endl;
		return ;
	}

	std::multiset<int>::iterator	second = this->_multiset.begin();
	std::multiset<int>::iterator	first = second++;
	int	shortestSpan = 0;
	int	currentSpan = 0;
	int	saveFirst = *first;
	int	saveSecond = *second;

	std::cout << "Calculating shortest span\n";
	shortestSpan = *second - *first;
	first = second++;
	while (first != (--this->_multiset.end()))
	{
		currentSpan = *second - *first;
		if (currentSpan < shortestSpan)
		{
			saveFirst = *first;
			saveSecond = *second;
			shortestSpan = currentSpan;
		}
		first = second++;
	}
	std::cout << "Evaluated pair is <" << saveFirst << ", " << saveSecond << '>'
			<< "\nShortest Span is " << shortestSpan
			<< std::endl;
}

void	Span::longestSpan(void)
{
	if (this->_multiset.size() <= 1)
	{
		std::cerr << "Longest span calculation can not proceed for the the containers does not contain enough values" << std::endl;
		return ;
	}
	int	small = *this->_multiset.begin();
	int	big = *(--this->_multiset.end());
	std::cout << "Calculating longest span\n";
	std::cout << "Smallest value is <" << small << '>'
			<< "\nBiggest value is <" << big << '>'
			<< "\nLongest Span is " << big - small
			<< std::endl;
}

const char	*Span::isFull::what(void) const throw()
{
	return ("Error: Container is already full");
}

const char	*Span::isNotBigEnough::what(void) const throw()
{
	return ("Error: Container is not big enough to store all this data");
}

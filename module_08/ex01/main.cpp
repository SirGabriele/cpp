/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:54:51 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/15 14:16:44 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <vector>

/*
[ -f ./out ] && rm ./out ; ./span > out ; perl -ne "print if s|^([0-9]*):.*\+([0-9]*)$|\2 index: \1|" out | sort -n -r ; cat out
*/

/*
%s/vector/list/g
%s/list/deque/g
*/

int length = 10; //tester avec 0 1 et 2

int	main(void)
{
	if (length <= 0)
	{
		std::cerr << "Please provide a length superior to 0" << std::endl;
		return (1);
	}
	std::srand(std::time(NULL));
	std::vector<int>				origin;
	Span						sp = Span(length);

	std::cout << "...Filling origin container...\n";
	for (int i = 0; i < length; i++)
		origin.push_back(std::rand() % 100);

	std::cout << "...Displaying origin container...\n";
	std::vector<int>::iterator	it = origin.begin();
	for (; it != origin.end(); it++)
		std::cout << *it << '\n';

	std::cout << "\n...Trying to use the origin container to fill sp...\n";
	try
	{
		sp.addNumbers(origin.begin(), origin.end());
		sp.addNumbers(origin.begin(), origin.end());//will throw an exception
	}
	catch(std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	std::cout << "\n...Trying to add one value to sp...\n";
	try
	{
		for (int i = 0; i < length; i++)
			sp.addNumber(std::rand() % 1000);
		sp.addNumber(-42);//will throw an exception
	}
	catch(std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	std::cout << "Content of Sp:\n";
	sp.printMultiset();
	std::cout << '\n';
	sp.longestSpan();
	std::cout << '\n';
	sp.shortestSpan();

		{
			std::cout << "\n------------------------------------------------------\n";
			std::cout << "Testing if the assignment operator works\n";
			Span	sp2(5);
			
			std::cout << "...Filling sp2 to its max capacity...\n";
			sp2.addNumber(1);
			sp2.addNumber(2);
			sp2.addNumber(3);
			sp2.addNumber(4);
			sp2.addNumber(5);
			sp2.printMultiset();
			std::cout << "sp2 = sp\n";
			sp2 = sp;
			sp2.printMultiset();
			try
			{
				sp2.addNumber(10);//will throw an exception
			}
			catch (std::exception &exception)
			{
				std::cerr << exception.what() << std::endl;
			}
			std::cout << '\n';
			sp2.longestSpan();
			std::cout << '\n';
			sp2.shortestSpan();
		}

		{
			std::cout << "\n------------------------------------------------------\n";
			std::cout << "Testing if the copy constructor works\n";
			Span	sp3(sp);
			
			std::cout << "...Filling sp3 to its max capacity...\n";
			sp3.printMultiset();
			try
			{
				sp3.addNumber(10);//will throw an exception
			}
			catch (std::exception &exception)
			{
				std::cerr << exception.what() << std::endl;
			}
			std::cout << '\n';
			sp3.longestSpan();
			std::cout << '\n';
			sp3.shortestSpan();
		}

	return (0);
}

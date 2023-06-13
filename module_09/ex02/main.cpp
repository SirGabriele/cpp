/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:11:38 by kbrousse          #+#    #+#             */
/*   Updated: 2023/06/13 11:19:43 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
Merge-insertion sort performs the following steps, on an input X of n elements.

1. Group the elements of X into n/2 pairs of elements, arbitrarily, leaving one element unpaired if there is an odd number of elements.

2. Perform n/2 comparisons, one per pair, to determine the larger of the two elements in each pair.

3. Recursively sort the n/2 larger elements from each pair, creating a sorted sequence S of n/2 of the input elements, in ascending order.

4. Insert at the start of S the element that was paired with the first and smallest element of S.

5.Insert the remaining n/2 - 1 elements of S, one at a time, with a specially chosen insertion ordering described below. Use binary search in subsequences of S (as described below) to determine the position at which each element should be inserted.
*/

/*
ARG=$(seq 0 10000 | shuf | tr '\n' ' ') ; ./PmergeMe $ARG
*/

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << B_HI_RED << "Error\n" << RESET << "Correct usage is: <./PmergeMe> <argument> [...]" << std::endl;
		return (1);
	}
	{
		std::cout << B_HI_YELLOW << "---Vector---\n" << RESET;
		struct timeval	start;
		gettimeofday(&start, NULL);

		for (int i = 1; argv[i] != NULL; i++)
		{
			std::string	sequence = argv[i];
			if (PmergeMe::isSequenceValid(sequence) != true
				|| PmergeMe::fillVector(argv[i]) != true)
				return (1);
		}

		std::cout << B_HI_CYAN << "Before:\t" << RESET;
		PmergeMe::displayVector();
		std::cout << '\n';
		
		PmergeMe::createPairsVector(PmergeMe::myVector);
		PmergeMe::pairVector = PmergeMe::sortPairsVector(PmergeMe::pairVector);
		PmergeMe::createMainSequenceVector(PmergeMe::pairVector);
		PmergeMe::insertPendingValuesVector(PmergeMe::pairVector);
		
		struct timeval	end;
		gettimeofday(&end, NULL);
		std::cout << B_HI_CYAN << "After:\t" << RESET;
		PmergeMe::displayVector();
		std::cout << "\n";
		std::cout << "Time to process a range of " << PmergeMe::myVector.size() << " elements with std::vector : " << (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec) << " µs\n\n";
	}
	{
		std::cout << B_HI_YELLOW << "---List---\n" << RESET;
		struct timeval	start;
		gettimeofday(&start, NULL);

		for (int i = 1; argv[i] != NULL; i++)
		{
			std::string	sequence = argv[i];
			if (PmergeMe::isSequenceValid(sequence) != true
				|| PmergeMe::fillList(argv[i]) != true)
				return (1);
		}

		std::cout << B_HI_CYAN << "Before:\t" << RESET;
		PmergeMe::displayList();
		std::cout << '\n';

		PmergeMe::createPairsList(PmergeMe::myList);
		PmergeMe::pairList = PmergeMe::sortPairsList(PmergeMe::pairList);
		PmergeMe::createMainSequenceList(PmergeMe::pairList);
		PmergeMe::insertPendingValuesList(PmergeMe::pairList);

		struct timeval	end;
		gettimeofday(&end, NULL);
		std::cout << B_HI_CYAN << "After:\t" << RESET;
		PmergeMe::displayList();
		std::cout << '\n';
		std::cout << "Time to process a range of " << PmergeMe::myList.size() << " elements with std::list : " << end.tv_usec - start.tv_usec << " µs" << std::endl;
	}
	return (0);
}

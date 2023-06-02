/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:11:38 by kbrousse          #+#    #+#             */
/*   Updated: 2023/06/02 18:59:03 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << B_HI_RED << "Error\n" << RESET << "Correct usage is: <./PmergeMe> <argument> [...]" << std::endl;
		return (1);
	}
	//vector
	{
		struct timeval	start;
		gettimeofday(&start, NULL);

		for (int i = 1; argv[i] != NULL; i++)
		{
			std::string	sequence = argv[i];
			if (PmergeMe::isSequenceValid(sequence) != true
				|| PmergeMe::fillVector(argv[i]) != true)
				return (1);

		}

		struct timeval	end;
		gettimeofday(&end, NULL);

		std::cout << "Time to process a range of 5 elements with std::vector : " << end.tv_usec - start.tv_usec << " µs" << std::endl;
	}
	//list
	{
		struct timeval	start;
		gettimeofday(&start, NULL);

		for (int i = 1; argv[i] != NULL; i++)
		{
			std::string	sequence = argv[i];
			if (PmergeMe::isSequenceValid(sequence) != true
				|| PmergeMe::fillList(argv[i]) != true)
				return (1);
		}

		struct timeval	end;
		gettimeofday(&end, NULL);

		std::cout << "Time to process a range of 5 elements with std::list : " << end.tv_usec - start.tv_usec << " µs" << std::endl;
	}

	//Vector
	std::cout << "---Vector---\n";
	std::cout << "Before:\t";
	PmergeMe::displayVector();
	std::cout << '\n';
	std::cout << "After:\t";
	PmergeMe::displayVector();
	std::cout << "\n\n";

	//List
	std::cout << "---List---\n";
	std::cout << "Before:\t";
	PmergeMe::displayList();
	std::cout << '\n';
	std::cout << "After:\t";
	PmergeMe::displayList();
	std::cout << '\n';
	return (0);
}

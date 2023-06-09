/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:13:00 by kbrousse          #+#    #+#             */
/*   Updated: 2023/06/02 18:54:47 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define WHITESPACES "\t\n\v\f\r "

# define B_HI_RED "\e[1;91m"
# define B_HI_GREEN "\e[1;92m"
# define B_HI_YELLOW "\e[1;93m"
# define RESET "\e[0m"

# include <iostream>
# include <string>
# include <cstring>		/*	std::strtok		*/
# include <cstdlib>		/*	std::strtol		*/
# include <sys/time.h>	/*	gettimeofday	*/
# include <limits>
# include <vector>
# include <list>

class	PmergeMe
{
	public:
		static bool	isSequenceValid(const std::string &);

		static bool	fillVector(char *);
		static bool	fillList(char *);

		static void	createPairsVector(std::vector<int> &);

		static std::vector<std::pair<int, int> >	sortPairsVector(std::vector<std::pair<int, int> > &);

		static std::vector<std::pair<int, int> >	mergePairsVector(std::vector<std::pair<int, int> > &, std::vector<std::pair<int, int> > &);

		static void	createMainSequenceVector(std::vector<std::pair<int, int> > &);

		static void	insertPendingValuesVector(std::vector<std::pair<int, int> > &);

		static int	binarySearchVector(std::vector<int> &, int, int, int);

		static void	displayVector(void);
		static void	displayList(void);


//		static std::vector<int>						insertSortVector(std::vector<int> &);
//		static std::vector<int>						&mergeInsertSort(std::vector<int> &);
//		static std::vector<int>						&getVector(void);

		static std::vector<std::pair<int, int> >	pairVector;
		static std::vector<int>	myVector;
		static std::list<int>	myList;

	private:
		PmergeMe(void);
		PmergeMe(const PmergeMe &);
		~PmergeMe(void);

		PmergeMe	&operator=(const PmergeMe &);

		static std::pair<bool, int>	_oddValue;

};

#endif /*PMERGEME_HPP*/

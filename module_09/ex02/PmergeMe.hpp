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
		static void	displayVector(void);
		static void	displayList(void);

	private:
		PmergeMe(void);
		PmergeMe(const PmergeMe &);
		~PmergeMe(void);

		PmergeMe	&operator=(const PmergeMe &);

		static std::vector<int>	_myVector;
		static std::list<int>	_myList;
};

#endif /*PMERGEME_HPP*/

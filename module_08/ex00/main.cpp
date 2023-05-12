/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:02:30 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/11 15:56:46 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>

/*
:%s/vector/list/g
:%s/list/deque/g
*/
int	main(void)
{
	std::srand(std::time(NULL));

	std::vector<int>			vector;
//	int							randomPlace = std::rand() % 50;
	int							toSearch = 50;

	for (int i = 0; i < 50; i++)
	{
		vector.push_back(std::rand() % 50);
/*		if (i == randomPlace)
			toSearch = vector.back();*/
	}

	std::cout << "toSearch = " << toSearch << '\n';

	std::vector<int>::const_iterator it = easyfind(vector, toSearch);
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
	{
		std::cout << *it;
		if (*it == toSearch)
		{
			std::cout << "\t <- found value\n";
			break ;
		}
		std::cout << '\n';
	}
	if (it == vector.end())
		std::cout << "Value was not found" << std::endl;
	return (0);
}

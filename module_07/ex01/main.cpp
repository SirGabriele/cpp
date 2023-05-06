/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:21:46 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/06 15:18:59 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>
#include <cctype>

void	toUpper(std::string &str)
{
	for (std::string::size_type i = 0; i < str.length(); i++)
	{
		if (str.at(i) >= 'a' && str.at(i) <= 'z')
			str.at(i) -= 32;
	}
}

void	toLower(std::string &str)
{
	for (std::string::size_type i = 0; i < str.length(); i++)
	{
		if (str.at(i) >= 'A' && str.at(i) <= 'Z')
			str.at(i) += 32;
	}
}

int	main(void)
{
	std::string	fullMin[] = {"hello", " i'm", " a", " string", " only", " composed", " of", " lowercase", " letters"};
	std::string	fullCap[] = {"HELLO", " I'M", " A", " STRING", " ONLY", " COMPOSED", " OF", " CAPITAL", " LETTERS"};
	std::string	mixed[] = {"hElLo", " I'm", " A", " sTrInG", " cOmPoSeD", " oF", " cApItAl", " LeTtErS", " aNd", " LoWeRcAsE", " lEtTeRs"};

	int sizeFullMin = sizeof(fullMin) / sizeof(std::string);
	int	sizeFullCap = sizeof(fullCap) / sizeof(std::string);
	int	sizeMixed = sizeof(mixed) / sizeof(std::string);

	std::cout << "Original arrays:\n";
	for (int i = 0; i < sizeFullMin; i++)
		std::cout << fullMin[i];
	std::cout << '\n';
	for (int i = 0; i < sizeFullCap; i++)
		std::cout << fullCap[i];
	std::cout << '\n';
	for (int i = 0; i < sizeMixed; i++)
		std::cout << mixed[i];
	std::cout << '\n' << std::endl;;

	iter(fullMin, sizeFullMin, toLower);
	iter(fullCap, sizeFullCap, toLower);
	iter(mixed, sizeMixed, toLower);

	std::cout << "Modified arrays:\n";
	for (int i = 0; i < sizeFullMin; i++)
		std::cout << fullMin[i];
	std::cout << '\n';
	for (int i = 0; i < sizeFullCap; i++)
		std::cout << fullCap[i];
	std::cout << '\n';
	for (int i = 0; i < sizeMixed; i++)
		std::cout << mixed[i];
	std::cout << '\n' << std::endl;;

	std::cout << "Re-modified arrays:\n";
	iter(fullMin, sizeFullMin, toUpper);
	iter(fullCap, sizeFullCap, toUpper);
	iter(mixed, sizeMixed, toUpper);

	for (int i = 0; i < sizeFullMin; i++)
		std::cout << fullMin[i];
	std::cout << '\n';
	for (int i = 0; i < sizeFullCap; i++)
		std::cout << fullCap[i];
	std::cout << '\n';
	for (int i = 0; i < sizeMixed; i++)
		std::cout << mixed[i];
	std::cout << std::endl;

	return (0);
}

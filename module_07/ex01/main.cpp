/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:21:46 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/05 13:59:34 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>
#include <cctype>

void	toUpper(char& c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
}

void	toLower(char& c)
{
	if (c >= 'A' && c <= 'Z')
	c += 32;
}

int	main(void)
{
	std::string	fullMin = "hello I'm a string only composef of lowercase letters";
	std::string	fullCap = "HELLO I'M A STRING ONLY COMPOSED OF CAPITAL LETTERS";
	std::string	mixed = "hElLo I'm A sTrInG cOmPoSeD oF cApItAl LeTtErS aNd LoWeRcAsE lEtTeRs";

	std::cout << fullMin << std::endl;
	std::cout << fullCap << std::endl;
	std::cout << mixed << '\n' << std::endl;

	iter(&fullMin, fullMin.length(), toUpper);
	iter(&fullCap, fullCap.length(), toUpper);
	iter(&mixed, mixed.length(), toUpper);

	std::cout << fullMin << std::endl;
	std::cout << fullCap << std::endl;
	std::cout << mixed << '\n' << std::endl;

	iter(&fullMin, fullMin.length(), toLower);
	iter(&fullCap, fullCap.length(), toLower);
	iter(&mixed, mixed.length(), toLower);

	std::cout << fullMin << std::endl;
	std::cout << fullCap << std::endl;
	std::cout << mixed << std::endl;

	return (0);
}

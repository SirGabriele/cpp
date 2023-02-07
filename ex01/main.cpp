/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:47:55 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/07 06:46:55 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <unistd.h>

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	user_input;

	do
	{
		std::cout << "Enter a command among the following:" << '\n';
		std::cout << "1. ADD" << '\n';
		std::cout << "2. SEARCH" << '\n';
		std::cout << "3. EXIT" << std::endl;
		std::cout << "► ";
		std::getline(std::cin, user_input);
		if (user_input.empty() && std::cin.eof() == false)
			continue ;
		else if (user_input == "ADD")
			phoneBook.addContact();
		else if (user_input == "SEARCH")
		{
			if (phoneBook.searchContact() == false)
				continue ;
		}
		else if (user_input == "EXIT")
			break ;
	}while (std::cin.eof() == false);
	std::cout << "\t\e[1;31mThis PhoneBook will self-destruct in 5 seconds" << '\n';
/*	sleep(1);
	for (int i = 5; i > 0; i--)
	{
		if (i == 3)
			std::cout << '\t' << i << " (you should run)" << '\n';
		else
			std::cout << '\t' << i << '\n';
		sleep(1);
	}
	std::cout << "\t     _.-^^---....,,--        " << '\n';
	std::cout << "\t _--                  --_    " << '\n';
	std::cout << "\t<                        >)  " << '\n';
	std::cout << "\t|                         |  " << '\n';
	std::cout << "\t \\._                   _./   " << '\n';
	std::cout << "\t    ```--. . , ; .--'''       " << '\n';
	std::cout << "\t          | |   |             " << '\n';
	std::cout << "\t       .-=||  | |=-.         " << '\n';
	std::cout << "\t       `-=#$%&%$#=-'         " << '\n';
	std::cout << "\t          | ;  :|            " << '\n';
	std::cout << "\t _____.,-#%&$@%#&#~,._____   \e[0m" << '\n';*/
	std::cout << "\tNo refund will be issued\e[0m" << std::endl;
	return (0);	
}

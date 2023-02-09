/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:47:55 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/09 11:55:19 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	user_input;

	do
	{
		std::cout << "Enter a command among the following:\n";
		std::cout << "1. ADD\n2. SEARCH\n3. EXIT" << std::endl;
		std::cout << "► ";
		std::getline(std::cin, user_input);
		if (user_input.empty()/* && std::cin.eof() == false*/)
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
	} while (std::cin.eof() == false);
	std::cout << "Thank you for using our service. See you next time !" << std::endl;
	return (0);	
}

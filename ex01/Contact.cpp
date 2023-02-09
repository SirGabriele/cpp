/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:51:01 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/09 09:22:17 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string	Contact::getFirstName(void) const
{
	return (this->_firstName);
}

void	Contact::setFirstName(void)
{
	std::string	user_input;

	do
	{
		std::cout << "What is your first name?" << '\n';
		std::cout << "► ";
		getline(std::cin, user_input);
		if (user_input.empty() == false)
			break ;
		if (std::cin.eof() == false)
			std::cout << "\e[1;31mThis field must be filled\e[0m" << std::endl;
	} while(std::cin.eof() == false);
	if (std::cin.eof())
		std::cout << "\e[1;31mYou press Ctrl-D, the adding process stops here\e[0m" << std::endl;
	else
		this->_firstName = user_input;
	return ;
}

std::string	Contact::getLastName(void) const
{
	return (this->_lastName);
}

void	Contact::setLastName(void)
{
	std::string	user_input;

	do
	{
		std::cout << "What is your last name?" << '\n';
		std::cout << "► ";
		getline(std::cin, user_input);
		if (user_input.empty() == false)
			break ;
		if (std::cin.eof() == false)
			std::cout << "\e[1;31mThis field must be filled\e[0m" << std::endl;
	} while(std::cin.eof() == false);
	if (std::cin.eof())
		std::cout << "\e[1;31mYou press Ctrl-D, the adding process stops here\e[0m" << std::endl;
	else
		this->_lastName = user_input;
	return ;
}

std::string	Contact::getNickname(void) const
{
	return (this->_nickname);
}

void	Contact::setNickname(void)
{
	std::string	user_input;

	do
	{
		std::cout << "What is your nickname?" << '\n';
		std::cout << "► ";
		getline(std::cin, user_input);
		if (user_input.empty() == false)
			break ;
		if (std::cin.eof() == false)
			std::cout << "\e[1;31mThis field must be filled\e[0m" << std::endl;
	} while(std::cin.eof() == false);
	if (std::cin.eof())
		std::cout << "\e[1;31mYou press Ctrl-D, the adding process stops here\e[0m" << std::endl;
	else
		this->_nickname = user_input;
	return ;
}

std::string	Contact::getPhoneNumber(void) const
{
	return (this->_phoneNumber);
}

void	Contact::setPhoneNumber(void)
{
	std::string	user_input;

	do
	{
		std::cout << "What is your phone number?" << '\n';
		std::cout << "► ";
		getline(std::cin, user_input);
		if (user_input.empty() == false)
			break ;
		if (std::cin.eof() == false)
			std::cout << "\e[1;31mThis field must be filled\e[0m" << std::endl;
	} while(std::cin.eof() == false);
	if (std::cin.eof())
		std::cout << "\e[1;31mYou press Ctrl-D, the adding process stops here\e[0m" << std::endl;
	else
		this->_phoneNumber = user_input;
	return ;
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->_darkestSecret);
}

void	Contact::setDarkestSecret(void)
{
	std::string	user_input;

	do
	{
		std::cout << "What is your darkest secret?" << '\n';
		std::cout << "► ";
		getline(std::cin, user_input);
		if (user_input.empty() == false)
			break ;
		if (std::cin.eof() == false)
			std::cout << "\e[1;31mThis field must be filled\e[0m" << std::endl;
	} while(std::cin.eof() == false);
	if (std::cin.eof())
		std::cout << "\e[1;31mYou press Ctrl-D, the adding process stops here\e[0m" << std::endl;
	else
		this->_darkestSecret = user_input;
	return ;
}

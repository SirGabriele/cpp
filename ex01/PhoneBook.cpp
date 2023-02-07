/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:49:44 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/07 06:53:36 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_currentContact = -1;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

int	PhoneBook::getCurrentContact(void) const
{
	return (this->_currentContact);
}

void	PhoneBook::setCurrentContact(void)
{
	this->_currentContact += 1;
	if (this->_currentContact == MAX_CONTACT)
		_currentContact = 0;
	return ;
}

void	PhoneBook::addContact(void)
{
	std::cout << "OMG you made a new friend? Let's add them to your phonebook !" << std::endl;
	this->setCurrentContact();
	if (std::cin.eof() == false)
		this->_contacts[this->_currentContact].setFirstName();
	if (std::cin.eof() == false)
		this->_contacts[this->_currentContact].setLastName();
	if (std::cin.eof() == false)
		this->_contacts[this->_currentContact].setNickname();
	if (std::cin.eof() == false)
		this->_contacts[this->_currentContact].setPhoneNumber();
	if (std::cin.eof() == false)
		this->_contacts[this->_currentContact].setDarkestSecret();
}

void	displayIndex(int index)
{
	std::cout << '|' << std::right << std::setw(10) << std::setfill(' ') << index << '|';
}

void	displayFirstName(Contact contact)
{
	std::string	info;

	info = contact.getFirstName();
	if (info.length() <= 10)
		std::cout << std::right << std::setw(10) << std::setfill(' ') << info << '|';
	//faire le else et truncate + mettre . a la fin
}

void	displayLastName(Contact contact)
{
	std::string	info;

	info = contact.getLastName();
	if (info.length() <= 10)
		std::cout << std::right << std::setw(10) << std::setfill(' ') << info << '|';
	//faire le else et truncate + mettre . a la fin
}

void	displayNickname(Contact contact)
{
	std::string	info;

	info = contact.getNickname();
	if (info.length() <= 10)
		std::cout << std::right << std::setw(10) << std::setfill(' ') << info << '|' << std::endl;
	//faire le else et truncate + mettre . a la fin
}

bool	PhoneBook::searchContact(void) const
{
	int	index;

	if (this->_currentContact == -1)
	{
		std::cout << "You do not have any contact in your phonebook for now. Take a curly" << std::endl;
		return (true);
	}
	std::cout << "Which contact would you like to display? (1-" << MAX_CONTACT << ")" << '\n';
	std::cout << "► ";
	std::cin >> index;
	if (std::cin.fail() == true || index == 0 || index > MAX_CONTACT)
	{
		std::cout << "Please provide a value between 1 and " << MAX_CONTACT << std::endl;//a tester avec "d"
		return (false);
	}
	std::cout << std::setfill('x') << std::setw(45) << '\n';
	displayIndex(index);
	displayFirstName(this->_contacts[index - 1]);
	displayLastName(this->_contacts[index - 1]);
	displayNickname(this->_contacts[index - 1]);
	std::cout << std::setfill('x') << std::setw(45) << std::endl;
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:49:44 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/09 12:00:12 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <sstream>
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook(void)
{
	this->_nbContact = -1;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

int	PhoneBook::getNbContact(void) const
{
	return (this->_nbContact);
}

void	PhoneBook::addContact(void)
{
	int	indexCurrentContact;

	this->_nbContact += 1;
	indexCurrentContact = this->getNbContact() % MAX_CONTACT;
	std::cout << "OMG you made a new friend? Let's add them to your phonebook !" << std::endl;
	if (std::cin.eof() == false)
		this->_contacts[indexCurrentContact].setFirstName();
	if (std::cin.eof() == false)
		this->_contacts[indexCurrentContact].setLastName();
	if (std::cin.eof() == false)
		this->_contacts[indexCurrentContact].setNickname();
	if (std::cin.eof() == false)
		this->_contacts[indexCurrentContact].setPhoneNumber();
	if (std::cin.eof() == false)
		this->_contacts[indexCurrentContact].setDarkestSecret();
	if (std::cin.eof() == false)
		std::cout << "\e[1;32mSuccessfully created contact [" << indexCurrentContact + 1 << "/" << MAX_CONTACT << "]\e[0m" << std::endl;
	else
		std::cout << "\e[1;31mFailed to create contact [" << indexCurrentContact + 1 << "/" << MAX_CONTACT << "]\e[0m" << std::endl;
}

void	PhoneBook::_displayIndex(int index_int) const
{
	std::cout << std::right << std::setw(10) << std::setfill(' ') << index_int << '|';
}

void	PhoneBook::_displayInfo(std::string info) const
{
	if (info.length() <= 10)
		std::cout << std::right << std::setw(10) << std::setfill(' ') << info << '|';
	else
		std::cout << std::left << std::setfill('.') << std::setw(10) << info.substr(0, 9) << '|';
}

bool	PhoneBook::_isNumeric(std::string const &str) const
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (std::isdigit(str.at(i)) == 0)
			return (false);
	}
	return (true);
}

bool	PhoneBook::_verifyIndex(int index_int) const
{
	if (index_int < 1 || index_int > MAX_CONTACT)
	{
		std::cout << "Please provide a value between 1 and " << MAX_CONTACT << std::endl;
		return (false);
	}
	else if (index_int > this->getNbContact() + 1)
	{
		std::cout << "You do not have that many contacts. Sorry for you" << '\n';
		return (false);
	}
	return (true);
}

void	PhoneBook::_displayOneContact(int index_int) const
{
	std::cout << "\tContact number : " << index_int;
	std::cout << "\n\tFirst name : " << this->_contacts[index_int - 1].getFirstName();
	std::cout << "\n\tLast name : " << this->_contacts[index_int - 1].getLastName();
	std::cout << "\n\tNickname : " << this->_contacts[index_int - 1].getNickname();
	std::cout << "\n\tPhone number : " << this->_contacts[index_int - 1].getPhoneNumber();
	std::cout << "\n\tDarkest secret : " << this->_contacts[index_int - 1].getDarkestSecret() << std::endl;
}

void	PhoneBook::_displayAllContacts(void) const
{
	std::cout << std::setfill('x') << std::setw(45) << "" << std::endl;
	std::cout << '|' << std::right << std::setw(10) << std::setfill(' ') << "Index" << '|';
	std::cout << std::right << "First Name" << '|';
	std::cout << std::right << std::setw(10) << std::setfill(' ') << "Last Name" << '|';
	std::cout << std::right << std::setw(10) << std::setfill(' ') << "Nickname" << '|' << std::endl;
	std::cout << std::setfill('x') << std::setw(45) << "" << std::endl;
	for (int i = 0; i < MAX_CONTACT; i++)
	{
		std::cout << '|';
		_displayIndex(i + 1);
		_displayInfo(this->_contacts[i].getFirstName());
		_displayInfo(this->_contacts[i].getLastName());
		_displayInfo(this->_contacts[i].getNickname());
		std::cout << std::endl;
	}
	std::cout << std::setfill('x') << std::setw(45) << "" << std::endl;
}

bool	PhoneBook::searchContact(void) const
{
	std::string	index;
	int			index_int;
	
	if (this->_nbContact == -1)
	{
		std::cout << "You do not have any contact in your phonebook for now. Take a curly" << std::endl;
		return (true);
	}
	this->_displayAllContacts();
	std::cout << "Which contact would you like to display? (1-" << MAX_CONTACT << ")\n";
	std::cout << "► ";
	std::getline(std::cin, index);
	if (_isNumeric(index) == false)
	{
		std::cout << "Non numeric character detected" << std::endl;
		return (false);
	}
	else if (!(std::stringstream(index) >> index_int))
	{
		if (std::cin.eof() == true)
			std::cout << "\e[1;31mYou pressed Ctrl-D, the searching process stops here\e[0m" << std::endl;
		return (false);
	}
	if (_verifyIndex(index_int) == true)
		this->_displayOneContact(index_int);
	else
		return (false);
	return (true);
}

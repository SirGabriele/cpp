/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:49:44 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/09 11:37:36 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# define MAX_CONTACT 8 

# include "Contact.hpp"

class	PhoneBook
{
public:

	PhoneBook(void);
	~PhoneBook(void);

	int 	getNbContact(void) const;

	void	addContact(void);

	bool	searchContact(void) const;

private:

	Contact _contacts[MAX_CONTACT];
	
	int		_nbContact;

	void	_displayOneContact(int index_int) const;
	void	_displayAllContacts(void) const;
	void	_displayIndex(int index_int) const;
	void	_displayInfo(std::string info) const;

	bool	_verifyIndex(int index_int) const;

	bool	_isNumeric(std::string const &str) const;
};

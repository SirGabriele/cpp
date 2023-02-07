/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:49:44 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/07 06:18:48 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# define MAX_CONTACT 8

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class	PhoneBook
{
public:

	PhoneBook(void);
	~PhoneBook(void);

	int 	getCurrentContact(void) const;
	void	setCurrentContact(void);

	void	addContact(void);//const? puisque modifie Contact et non PhoneBook

	bool	searchContact() const;

private:

	Contact _contacts[MAX_CONTACT];
	int		_currentContact;
};

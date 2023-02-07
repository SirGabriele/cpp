/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:49:44 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/07 04:49:27 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <iomanip>

class	Contact
{
public:

	Contact(void);
	~Contact(void);

	std::string	getFirstName(void) const;
	void		setFirstName(void);

	std::string	getLastName(void) const;
	void		setLastName(void);

	std::string	getNickname(void) const;
	void		setNickname(void);

	std::string	getPhoneNumber(void) const;
	void		setPhoneNumber(void);

	std::string	getDarkestSecret(void) const;
	void		setDarkestSecret(void);

private:

	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:19:21 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/24 10:17:12 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{

}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern::~Intern(void)
{

}

Intern	&Intern::operator=(const Intern &src)
{
	(void)src;
	return (*this);
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	AForm		*form = NULL;
	std::string	array[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int			i = 0;

	if (name.empty() == true || target.empty() == true)
		throw StringIsEmpty();
	for (; i < 3; i++)
	{
		if (array[i] == name)
			break ;
	}
	switch (i)
	{
		case 0:
		{
			form = new ShrubberyCreationForm(target);
			break ;
		}
		case 1:
		{
			form = new RobotomyRequestForm(target);
			break ;
		}
		case 2:
		{
			form = new PresidentialPardonForm(target);
			break ;
		}
		default :
		{
			throw StringIsInvalid();
			break ;
		}
	}
	return (form);
}

Intern::StringIsEmpty::StringIsEmpty(void) throw(): _errorMsg("At least one of the specified strings is empty")
{

}

Intern::StringIsEmpty::~StringIsEmpty(void) throw()
{

}

const char	*Intern::StringIsEmpty::what(void) const throw()
{
	return (this->_errorMsg.c_str());
}

Intern::StringIsInvalid::StringIsInvalid(void) throw(): _errorMsg("The name field does not correspond to any known form name. Known form names are:\n- shrubbery creation\n- robotomy request\n- presidential pardon")
{

}

Intern::StringIsInvalid::~StringIsInvalid(void) throw()
{

}

const char	*Intern::StringIsInvalid::what(void) const throw()
{
	return (this->_errorMsg.c_str());
}

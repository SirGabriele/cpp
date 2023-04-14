/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:10:49 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/13 18:33:25 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice(void): AMateria()
{
	//std::cout << "Ice default constructor called" << std::endl;
	this->_type = "ice";
}

Ice::Ice(const Ice &src): AMateria()
{
//	std::cout << "Ice copy constructor called" << std::endl;
	*this = src;
}

Ice::~Ice(void)
{
	//std::cout << "Ice destructor called" << std::endl;
}

Ice	&Ice::operator=(const Ice &src)
{
	(void)src;
	return (*this);
}

AMateria	*Ice::clone(void) const
{
	AMateria	*cloned = new Ice();

	return (cloned);
}

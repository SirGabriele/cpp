/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:32:38 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/01 14:36:30 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void): _name("Gaspard"), _age(26), _alive(true)
{

}

Data::Data(const std::string &name, int age, bool alive): _name(name), _age(age), _alive(alive)
{

}

Data::Data(const Data &src)
{
	*this = src;
}

Data::~Data(void)
{

}

Data	&Data::operator=(const Data &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_age = src._age;
		this->_alive = src._alive;
	}
	return (*this);
}

const std::string	&Data::getName(void) const
{
	return (this->_name);
}

void	Data::setName(const std::string &name)
{
	this->_name = name;
}

int	Data::getAge(void) const
{
	return (this->_age);
}

void	Data::setAge(int age)
{
	this->_age = age;
}

bool	Data::getAlive(void) const
{
	return (this->_alive);
}

void	Data::setAlive(bool alive)
{
	this->_alive = alive;
}

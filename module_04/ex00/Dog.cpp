/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:50:17 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/11 19:17:03 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &src): Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &src)
{
	if (this != &src)
	{
		this->type = src.type;
	}
	return (*this);
}

void	Dog::makeSound(void)
{
	std::cout << "*barks*" << std::endl;
}

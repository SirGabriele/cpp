/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:59:39 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/11 19:17:55 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "cat";
}

Cat::Cat(const Cat &src): Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &src)
{
	if (this != &src)
	{
		this->type = src.type;
	}
	return (*this);
}

void	Cat::makeSound(void)
{
	std::cout << "*meows*" << std::endl;
}

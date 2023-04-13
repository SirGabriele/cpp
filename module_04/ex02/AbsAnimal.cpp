/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbsAnimal.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:37:30 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/13 16:19:33 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbsAnimal.hpp"

AbsAnimal::AbsAnimal(void): type("AbsAnimal")
{
	std::cout << "AbsAnimal default constructor called" << std::endl;
}

AbsAnimal::AbsAnimal(const AbsAnimal &src)
{
	std::cout << "AbsAnimal copy constructor called" << std::endl;
	*this = src;
}

AbsAnimal::~AbsAnimal(void)
{
	std::cout << "AbsAnimal destructor called" << std::endl;
}

AbsAnimal	&AbsAnimal::operator=(const AbsAnimal &src)
{
	if (this != &src)
	{
		this->type = src.type;
	}
	return (*this);
}

void	AbsAnimal::makeSound(void)
{
	std::cout << "*undefined animal noise*" << std::endl;
}

std::string	AbsAnimal::getType(void)
{
	return (this->type);
}

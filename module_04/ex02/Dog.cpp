/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:50:17 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/13 16:20:26 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(void): AbsAnimal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &src): AbsAnimal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

Dog	&Dog::operator=(const Dog &src)
{
	if (this != &src)
	{
		this->type = src.type;
		for (int i = 0; i < 100; i++)
			this->_brain->_ideas[i] = src._brain->_ideas[i];
	}
	return (*this);
}

void	Dog::makeSound(void)
{
	std::cout << "*barks*" << std::endl;
}

Brain	&Dog::getBrain(void)
{
	return (*this->_brain);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:44:46 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/13 19:12:10 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void): ICharacter()
{
	std::cout << "Character default constructor called" << std::endl;
	this->_name = "Default";
	this->_inventory[0] = NULL;
	this->_inventory[1] = NULL;
	this->_inventory[2] = NULL;
	this->_inventory[3] = NULL;
}

Character::Character(const std::string &name): ICharacter()
{
	std::cout << "Character parametric constructor called" << std::endl;
	this->_name = name;
	this->_inventory[0] = NULL;
	this->_inventory[1] = NULL;
	this->_inventory[2] = NULL;
	this->_inventory[3] = NULL;
}

Character::Character(const Character &src): ICharacter()
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = src;
}

Character::~Character(void)
{
	std::cout << "Character destructor called" << std::endl;
}

Character	&Character::operator=(const Character &src)
{
	if (this != &src)
	{
		for (int i = 0; i < INVENTORYSLOTS; i++)
			this->_inventory[i] = src._inventory[i];
	}
	return (*this);
}

const AMateria	*Character::getSlot(int i) const
{
	if (i < 0 || i > INVENTORYSLOTS)
	{
		std::cerr << "The inventory slots go from 0 to 3" << std::endl;
		return (NULL);
	}
	else
		return (this->_inventory[i]);
}

const std::string	&Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	int	i = 0;

	while (this->_inventory[i] != NULL)
		i++;
	if (i == 3)
		return ;
	else
		this->_inventory[i] = m;
}

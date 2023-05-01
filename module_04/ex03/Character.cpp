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

Character::Character(void)
{
	std::cout << "Character default constructor called" << std::endl;
	this->_name = "Default";
	for (int i = 0; i < INVENTORYSLOTS; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const std::string &name)
{
	std::cout << "Character parametric constructor called" << std::endl;
	this->_name = name;
	for (int i = 0; i < INVENTORYSLOTS; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character &src)
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < INVENTORYSLOTS; i++)
		this->_inventory[i] = NULL;
	*this = src;
}

Character::~Character(void)
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < INVENTORYSLOTS; i++)
		delete this->getSlot(i);
}

Character	&Character::operator=(const Character &src)
{
	if (this != &src)
	{
		for (int i = 0; i < INVENTORYSLOTS; i++)
		{
			if (this->_inventory[i] != NULL)
				delete this->_inventory[i];
			if (src._inventory[i] != NULL)
				this->_inventory[i] = src._inventory[i]->clone();
		}
	}
	return (*this);
}

const AMateria	*Character::getSlot(int i) const
{
	if (i < 0 || i > INVENTORYSLOTS - 1)
	{
		std::cerr << "Action impossible. The inventory slots go from 0 to " << INVENTORYSLOTS - 1 << std::endl;
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

	if (m == NULL)
	{
		std::cerr << "Can not equip this Materia for it is equal to NULL." << std::endl;
		return ;
	}
	while (i < INVENTORYSLOTS && this->_inventory[i] != NULL && this->_inventory[i] != m)
		i++;
	if (this->_inventory[i] == m)
	{
		std::cerr << "Can not equip this Materia for it is already in the inventory" << std::endl;
		return ;
	}
	if (i == INVENTORYSLOTS)
	{
		std::cerr << "Can not equip this Materia for this Character's inventory is full" << std::endl;
		return ;
	}
	else
		this->_inventory[i] = m;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > INVENTORYSLOTS - 1)
	{
		std::cerr << "Action impossible. The inventory slots go from 0 to " << INVENTORYSLOTS - 1<< std::endl;
		return ;
	}
	else if (this->_inventory[idx] != NULL)
		this->_inventory[idx] = NULL;
	else
		std::cerr << "Can not unequip item in slot " << idx << ". Slot is empty" << std::endl;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > INVENTORYSLOTS - 1)
	{
		std::cerr << "Action impossible. The inventory slots go from 0 to " << INVENTORYSLOTS - 1<< std::endl;
		return ;
	}
	else if (this->_inventory[idx] == NULL)
		std::cout << "Can not use this Materia for there is nothing in this slot" << std::endl;
	else
		this->_inventory[idx]->use(target);	
}

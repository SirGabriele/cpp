/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:18:23 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/08 18:38:03 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(10), _maxHitPoints(_hitPoints)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(10), _maxHitPoints(_hitPoints)
{
	std::cout << "Naming constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
			<< this->_attackDamage << " points of damage" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " does not have enough Energy Points or Hit Points to complete this action" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no remaining HP. No need to set upon its dying body" << std::endl;
	}
	else if (amount > this->_hitPoints)
	{
		std::cout << "Dealing " << amount << " points of damage to ClapTrap " << this->_name
			<< ". That's a bit overkill since ClapTrap" << this->_name << " only had "
			<< this->_hitPoints << " remaining" << std::endl;
		this->_hitPoints = 0;
	}
	else
	{
		this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage. Setting its remaining life to " << this->_hitPoints << " HP" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		if (amount >= this->_maxHitPoints || this->_hitPoints + amount >= this->_maxHitPoints)
		{
			this->_hitPoints = this->_maxHitPoints;
			std::cout << "You tried to repair ClapTrap " << this->_name
					<< " of " << amount << " HP. However it is designed to have "
					<< _maxHitPoints << " max Hit Points. Setting its remaining life to "
					<< this->_hitPoints << " HP" << std::endl;
		}
		else
			this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " repaired itself of " << amount
				<< " Hit Points. Setting its remaining life to " << this->_hitPoints
				<< " HP" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " does not have enough Energy Points or Hit Points to complete this action" << std::endl;
}

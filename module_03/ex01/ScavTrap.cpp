/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:49:47 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/10 16:25:29 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_maxHitPoints = _hitPoints;
	this->_isKeepingGate = false;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap naming constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_maxHitPoints = _hitPoints;
	this->_isKeepingGate = false;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing "
			<< this->_attackDamage << " points of damage" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "ScavTrap " << this->_name << " does not have enough Energy Points or Hit Points to complete this action" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		if (this->_isKeepingGate == false)
		{
			std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
			this->_isKeepingGate = true;
		}
		else
			std::cout << "ScavTrap" << this->_name << " is already in Gate keeper mode" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " does not have enough Energy Points or Hit Points to complete this action" << std::endl;
}

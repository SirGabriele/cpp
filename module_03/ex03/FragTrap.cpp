/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:14:04 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/11 14:09:04 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_maxHitPoints = _hitPoints;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap naming constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_maxHitPoints = _hitPoints;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap(src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &src)
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

void	FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints > 0)
		std::cout << "FragTrap " << this->_name << " gives a high five" << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " does not have enough Energy Points or Hit Points to complete this action." << std::endl;
}

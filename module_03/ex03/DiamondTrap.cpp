/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:07:31 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/10 20:31:37 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap("Default_clap_name"), FragTrap("Default_clap_name"), ScavTrap("Default_clap_name")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = 30;

}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap naming constructor called" << std::endl;
	this->_name = (name);
	this->_hitPoints = 100;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src): ClapTrap(src._name + "_clap_name"), FragTrap(src._name + "_clap_name"), ScavTrap(_name + "_clap_name")
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = src;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &src)
{
	if (this != &src)
	{
		this->_name = (src._name + "clap_name");
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:07:27 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/10 19:30:25 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class	DiamondTrap: public FragTrap, public ScavTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &src);
		~DiamondTrap(void);

		DiamondTrap	&operator=(const DiamondTrap &src);

		void	whoAmI(void);

		std::string		getName(void);
		unsigned int	getHitPoints(void);
		unsigned int	getEnergyPoints(void);
		unsigned int	getAttackDamage(void);
		unsigned int	getMaxHitPoints(void);

	private:
		std::string	_name;
};

#endif /*DIAMONTRAP_HPP*/

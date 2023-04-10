/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:37:15 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/10 16:25:13 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap: public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &src);
		~ScavTrap(void);

		ScavTrap	&operator=(const ScavTrap &src);

		void	attack(const std::string &name);
		void	guardGate(void);

	private:
		bool	_isKeepingGate;
};

#endif /*SCAVTRAP_HPP*/

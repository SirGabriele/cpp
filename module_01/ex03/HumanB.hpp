/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:59:33 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/10 15:37:37 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class	HumanB
{
public:

	HumanB(std::string name);
	~HumanB(void);

	void	setWeapon(Weapon &weapon);

	void	attack(void);

private:

	Weapon		*_weapon;
	std::string	_name;
};

#endif /*HUMANB_HPP*/

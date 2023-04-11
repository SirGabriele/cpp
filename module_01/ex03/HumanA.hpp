/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:59:33 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/10 16:40:57 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class	HumanA
{
public:

	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);

	void	attack(void) const;

private:

	Weapon		&_weapon;
	std::string	_name;
};

#endif /*HUMANA_HPP*/

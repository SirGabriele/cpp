/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:57:49 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/10 16:41:51 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class	Weapon
{
public:

	Weapon(std::string type);
	~Weapon(void);
	
	const std::string	&getType(void) const;
	void				setType(std::string type);

private:

	std::string	_type;
};

#endif /*WEAPON_HPP*/

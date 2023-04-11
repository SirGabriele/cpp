/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:26:16 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/13 18:22:14 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "A zombie from the horde is being created" << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << "Sorry son " << this->_name << " was rabid, had to put it down" << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::name(std::string name)
{
	this->_name = name;
	return ;
}

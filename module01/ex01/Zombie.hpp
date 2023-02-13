/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:19:12 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/10 14:27:11 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class	Zombie
{
public:

	Zombie(void);
	~Zombie(void);

	void	announce(void);

	void	name(std::string name);

private:

	std::string	_name;
};

#endif /*ZOMBIE_HPP*/

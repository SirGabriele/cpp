/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:14:12 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/10 14:38:09 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*horde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		horde[i].name(name);
		std::cout << "Completing the paperwork to name zombie [" << i + 1 << '/' << N << "] \'" << name << "\'" << std::endl;
	}
	return (horde);
}

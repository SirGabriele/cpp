/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:19:51 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/10 14:39:23 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
Zombie* zombieHorde(int N, std::string name);

int	main(void)
{
	Zombie	*horde;
	int		N;

	N = 18;
	if (N <= 0)
		return (0);
	horde = zombieHorde(N, "Rousseau");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete [] horde;
	std::cout << "Sorry son the horde was rabid, had to put it down" << std::endl;
	return (0);
}
